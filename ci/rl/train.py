import torch
import torch.nn as nn
import torch.optim as optim
import pandas as pd
import numpy as np

df = pd.read_csv("dataset_with_rewards.csv")

# Estados (7 features)
state_cols = ["pos_izq","pos_der","vel_izq","vel_der","yaw","error_traj","dist_restante"]
states = df[state_cols].values.astype(np.float32)
actions = df[["delta_v"]].values.astype(np.float32)
rewards = df[["reward"]].values.astype(np.float32)
dones = df[["done"]].astype(np.float32).values

# Normalización (media-std por columna)
state_mean = states.mean(axis=0, keepdims=True)
state_std = states.std(axis=0, keepdims=True) + 1e-6
states_norm = (states - state_mean) / state_std

# next_states por episodio (no cruzar límites)
next_states = np.roll(states_norm, -1, axis=0)
for i in range(len(dones)):
    if dones[i] == 1:
        next_states[i] = states_norm[i]  # terminal: no avanzamos

class QNet(nn.Module):
    def __init__(self, state_dim=7, action_dim=1):
        super().__init__()
        self.fc1 = nn.Linear(state_dim + action_dim, 64)
        self.fc2 = nn.Linear(64, 32)
        self.fc3 = nn.Linear(32, 1)
    def forward(self, state, action):
        x = torch.cat([state, action], dim=1)
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        return self.fc3(x)

# Red principal y red objetivo
q = QNet()
q_target = QNet()
q_target.load_state_dict(q.state_dict())
optimizer = optim.Adam(q.parameters(), lr=1e-3)
criterion = nn.MSELoss()
gamma = 0.99

# Tensores
states_t = torch.tensor(states_norm)
actions_t = torch.tensor(actions)
rewards_t = torch.tensor(rewards)
next_states_t = torch.tensor(next_states)
dones_t = torch.tensor(dones)

# Entrenamiento con mini-batches
batch_size = 64
num_epochs = 200
tau = 0.01  # soft update

N = len(states_t)
indices = np.arange(N)

for epoch in range(num_epochs):
    np.random.shuffle(indices)
    for start in range(0, N, batch_size):
        idx = indices[start:start+batch_size]
        s = states_t[idx]
        a = actions_t[idx]
        r = rewards_t[idx]
        d = dones_t[idx]
        s_next = next_states_t[idx]

        # Q(s,a)
        q_sa = q(s, a)

        # Objetivo: r + gamma * Q_target(s', a') * (1 - done)
        # Simplificación: usar misma acción como proxy de a' (acciones continuas)
        with torch.no_grad():
            q_next = q_target(s_next, a)
            target = r + gamma * q_next * (1 - d)

        loss = criterion(q_sa, target)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        # Soft update de la red objetivo
        with torch.no_grad():
            for p, p_t in zip(q.parameters(), q_target.parameters()):
                p_t.data.mul_(1 - tau).add_(tau * p.data)

    if epoch % 20 == 0:
        print(f"Epoch {epoch}, Loss {loss.item():.6f}")

# Exportar a TorchScript
example_state = states_t[:1]
example_action = actions_t[:1]
traced = torch.jit.trace(q, (example_state, example_action))
traced.save("model_rl.pt")
print("Entrenamiento terminado y modelo guardado en model_rl.pt")
