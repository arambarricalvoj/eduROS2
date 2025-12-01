import torch
print(torch.__version__)          # versión de PyTorch
print(torch.version.cuda)         # versión de CUDA usada por PyTorch
print(torch.cuda.is_available())  # True si detecta la GPU
print(torch.cuda.get_device_name(0))  # nombre de tu GPU
