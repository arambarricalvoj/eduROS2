import time
from inputs import get_gamepad

# Mapeo estándar de botones DualShock4
BOTON_X = 'BTN_SOUTH'       # X
BOTON_O = 'BTN_EAST'        # Círculo
BOTON_CUADRADO = 'BTN_WEST' # Cuadrado
BOTON_TRIANGULO = 'BTN_NORTH' # Triángulo

# Ejes de los sticks
EJE_LX = 'ABS_X'
EJE_LY = 'ABS_Y'
EJE_RX = 'ABS_RX'
EJE_RY = 'ABS_RY'

# Variables para guardar la última posición de cada stick
lx = ly = rx = ry = 0

print("Escuchando mando DualShock4...")
print("Pulsa X, O, Cuadrado o Triángulo para ver mensajes.")
print("Posición de sticks se mostrará cada 2 segundos.")

ultimo_print = time.time()

while True:
    events = get_gamepad()
    for event in events:
        # --- BOTONES ---
        if event.code == BOTON_X and event.state == 1:
            print("Has pulsado: X")
        elif event.code == BOTON_O and event.state == 1:
            print("Has pulsado: O (Círculo)")
        elif event.code == BOTON_CUADRADO and event.state == 1:
            print("Has pulsado: Cuadrado")
        elif event.code == BOTON_TRIANGULO and event.state == 1:
            print("Has pulsado: Triángulo")

        # --- STICKS ---
        elif event.code == EJE_LX:
            lx = event.state
        elif event.code == EJE_LY:
            ly = event.state
        elif event.code == EJE_RX:
            rx = event.state
        elif event.code == EJE_RY:
            ry = event.state

    # Mostrar posición de sticks cada 2 segundos
    if time.time() - ultimo_print >= 2.0:
        print(f"Stick Izquierdo: X={lx}  Y={ly}   |   Stick Derecho: X={rx}  Y={ry}")
        ultimo_print = time.time()
