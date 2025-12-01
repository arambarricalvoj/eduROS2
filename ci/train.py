import torch
import torch.nn as nn
import pandas as pd

# Cargar dataset
df = pd.read_csv("dataset.csv")
#df1 = pd.read_csv("dataset1.csv")

#df = pd.concat([df0, df1], ignore_index=True)

X = df[["pos_izq","pos_der","vel_izq","vel_der","yaw","error_traj","dist_restante"]].values
y = df[["delta_v"]].values

X = torch.tensor(X, dtype=torch.float32)
y = torch.tensor(y, dtype=torch.float32)

# Ajustar etiquetas para reforzar constraint
d_max = df["dist_restante"].max()
alpha = 0.5
y_mod = y * (1.0 + alpha * (1.0 - df["dist_restante"].values/d_max).reshape(-1,1))
y_mod = torch.tensor(y_mod, dtype=torch.float32)

# Definir red
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.fc1 = nn.Linear(7, 32)
        self.fc2 = nn.Linear(32, 16)
        self.fc3 = nn.Linear(16, 1)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        return self.fc3(x)

model = Net()
criterion = nn.MSELoss()
optimizer = torch.optim.Adam(model.parameters(), lr=0.001)

# Entrenamiento
for epoch in range(200):
    optimizer.zero_grad()
    outputs = model(X)
    loss = criterion(outputs, y_mod)
    loss.backward()
    optimizer.step()
    if epoch % 20 == 0:
        print(f"Epoch {epoch}, Loss {loss.item()}")

# Exportar a TorchScript
traced = torch.jit.trace(model, X)
traced.save("model.pt")
