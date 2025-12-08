import pandas as pd
import numpy as np

df = pd.read_csv("dataset.csv")
df["done"] = df["done"].astype(int)
df["reward"] = 0  # inicializamos

start_idx = 0
while start_idx < len(df):
    yaw_offset = df.loc[start_idx, "yaw"]

    # buscar fin de episodio
    end_idx = start_idx
    while end_idx < len(df) and df.loc[end_idx, "done"] != 1:
        # recompensa intermedia: ±1 según yaw respecto al offset
        yaw_curr = df.loc[end_idx, "yaw"]
        yaw_diff = abs(yaw_curr - yaw_offset)
        df.loc[end_idx, "reward"] = 0 if yaw_diff <= 5.0 else 0
        end_idx += 1

    if end_idx >= len(df):
        break

    # recompensa final grande
    yaw_final = df.loc[end_idx, "yaw"]
    yaw_diff = abs(yaw_final - yaw_offset)
    df.loc[end_idx, "reward"] = 10 if yaw_diff <= 2.0 else -10

    start_idx = end_idx + 1

df.to_csv("dataset_with_rewards.csv", index=False)
print("Rewards intermedias (+1/-1) y finales (+10/-10) asignadas")
