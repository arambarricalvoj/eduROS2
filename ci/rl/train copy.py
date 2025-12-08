import torch
import torch.nn as nn
import torch.optim as optim
import pandas as pd
import numpy as np

# ============================
# 1. Cargar dataset
# ============================
df = pd.read_csv("dataset_with_rewards.csv")

# Estados (7 features)
states = df[["pos_izq","pos_der","vel_izq","vel_der","yaw","error_traj","dist_restante"]].values
actions = df[["delta_v"]].values
rewards = df[["reward"]].values
dones = df[["done"]].astype(int).values

# Construir next_states desplazando una fila dentro del mismo episodio
next_states = np.roll(states, -1, axis=0)
# Para las transiciones con done=1, el siguiente estado se iguala al actual
for i in range(len(dones)):
    if dones[i] == 1:
        next_states[i] = states[i]

# Convertir a tensores
states_t = torch.tensor(states, dtype=torch.float32)
actions_t = torch.tensor(actions, dtype=torch.float32)
rewards_t = torch.tensor(rewards, dtype=torch.float32)
next_states_t = torch.tensor(next_states, dtype=torch.float32)
dones_t = torch.tensor(dones, dtype=torch.float32)

# ============================
# 2. Definir red Q-learning
# ============================
class QNet(nn.Module):
    def __init__(self, state_dim=7, action_dim=1):
        super(QNet, self).__init__()
        self.fc1 = nn.Linear(state_dim + action_dim, 64)
        self.fc2 = nn.Linear(64, 32)
        self.fc3 = nn.Linear(32, 1)

    def forward(self, state, action):
        x = torch.cat([state, action], dim=1)
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        return self.fc3(x)  # Q-value

model = QNet()
optimizer = optim.Adam(model.parameters(), lr=0.001)
criterion = nn.MSELoss()

gamma = 0.99  # factor de descuento

# ============================
# 3. Entrenamiento offline
# ============================
for epoch in range(200):
    # Q(s,a)
    q_values = model(states_t, actions_t)

    # Q target = r + gamma * Q(s',a') * (1-done)
    with torch.no_grad():
        q_next = model(next_states_t, actions_t)
        q_target = rewards_t + gamma * q_next * (1 - dones_t)

    loss = criterion(q_values, q_target)

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if epoch % 20 == 0:
        print(f"Epoch {epoch}, Loss {loss.item()}")

# ============================
# 4. Exportar modelo a TorchScript
# ============================
example_state = states_t[:1]
example_action = actions_t[:1]
traced = torch.jit.trace(model, (example_state, example_action))
traced.save("model_rl.pt")

print("Entrenamiento terminado y modelo guardado en model_rl.pt")
