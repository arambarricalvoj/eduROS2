# Arrancar el programa 

## 1. Encender el Lego Mindstorms EV3.

Encender el Lego Mindstorms EV3 y conectarlo, a través del dongle wifi NETGEAR a la misma red wifi que el ordenador.
Seguir los pasos de [ev3_wifi_configuration]().

## 2. Conexión SSH con el robot.

Una vez que el robot está conectado a la misma red y nos ha proporcinado su dirección IP, podemos conectarnos a través de SSH. 
La contraseña es ``maker``. 

```bash
ssh robot@ev3dev.local
```

o bien 
```bash
ssh robot@DIRECCION_IP
```

IMAGEN PANTALLA CON DIRECCIÓN IP


## 3. Arrancar ROS2 en Docker

Se utiliza ROS2 Jazzy en un contenedor Docker. Es posible trabajar con ROS2 instalado en el propio sistema, y en este caso se debe omitir este paso. Se utiliza una imagen generada a partir de la oficial, que ya incluye las librerías de Python necesarias.

Para facilitar este arranque se ha configurado el fichero ``run.sh`` para desplegar el contenedor de Docker con el directorio del paquete de ROS2 compartido. 
Ejecutar el fichero:

```bash
./run.sh
```

El contenido del ejecutable es el siguiente:
```
xhost +local:*
docker run -e DISPLAY=$DISPLAY \
           -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
           -v /home/$USER/Documents/tfg/tfg_ev3/comm/ros2/mounted:/home/$USER/mounted/ \
           --device /dev/dri:/dev/dri \
           -it \
           --gpus all \
           --name ros_jazzy_instance ros2_mvsim:latest
```

- ``xhost +local:*`` permite abrir herramientas gráficas del sistema del contenedor como si las estuviéramos abriendo en el propio sistema. Es necesario
pasar como parámetro la variable de entorno ``$DISPLAY``: ``-e DISPLAY=$DISPLAY`` y compartir su fichero con el contenedor: ``-v /tmp/.X11-unix/:/tmp/.X11-unix/``.

- ``-v /home/$USER/Documents/tfg/tfg_ev3/comm/ros2/mounted:/home/$USER/mounted/`` para compartir la carpeta ``/home/$USER/Documents/tfg/tfg_ev3/comm/ros2/mounted`` de nuestro ordenador con el contenedor en el directorio /home/$USER/mounted/.

- ``--device /dev/dri:/dev/dri`` para pasar al contenedor la aceleración gráfica necesaria para RVIZ2 (OpenGL, MESA, glx, iris)

- ``-it`` para abrir una terminal interactiva del contenedor.

- ``--gpus all`` para compartir las gpus con el contenedor.

- ``--name ros_jazzy_instance ros2_mvsim:latest`` para dar un nombre al contenedor (``ros_jazzy_instance``) y arrancar la imagen deseada (``ros2_mvsim:latest``).


## 4. Activar ROS2


Desde la terminal del sistema en la que se encuentra ROS2, bien sead del contenedor de Docker o del propio sistema, ejecutar:

```bash
source /opt/ros/jazzy/setup.bash
```

Comprobamos que se ha activado correctamente imprimiendo la variable de entorno ``$ROS_DISTRO``. Si la salida no es vacía contiene una cadena identificativa de la distirbución de ROS2, entonces se ha activado correctamente:
```bash
echo $ROS_DISTRO
```

## 5. Instalar las librerías de Python necesarias
```bash
sudo apt update
sudo apt upgrade
```

```bash
sudo apt install python3-pynput
```

## 6. Compilar y activar el paquete ``ip_nodes``

Para ejecutar el programa tendremos que compilarlo. Desde terminal ir al workspace del paquete:
```bash
cd /home/$USER/mounted/ws
```

Compilar el workspace:
```bash
colcon build --symlink-install
```

Activar el workspace como overlay de ROS2:
```bash
cd /home/$USER/mounted/ws
source install/setup.bash
```

## 7. Ejecutar el servidor en el robot EV3
Copiar el script XXX en el robot mediante SSH. En una terminal del ordenador ejecutar:
```bash
scp /path/to/local/file username@remote_ip:/path/to/remote/directory
```

Ejemplo:
```bash
scp server_ev3.py robot@192.168.1.140:/home/robot
```
En la terminal SSH del robot, cuando ya estamos conectados al robot, ejecutar:
```bash
python3 nombre_script.py.
```

Ejemplo:
```bash
python3 server_ev3.py
```

El robot ya está escuchando lo que el cliente le mande.

## 7. Ejecutar el cliente basado en nodos de ROS2 
Si trabajamos con ROS2 directamente instalador en el sistema saltar a la activación de ROS2 y la overlay.

Si trabajamos desde Docker abrir una nueva terminal del contenedor. Primero hay que obtener el ID del contenedor con:
```bash
docker ps 
```

En la salida veremos todos los contenedores que están en ejecución. Buscamos el nuestro viendo los nombres de cada uno y copiamos el ``CONTAINER ID``.

Abrimos una nueva terminal en el ordenador y ejecutamos:
```bash
docker exec -it CONTAINER_ID bash
```

En esta nueva terminal activamos tanto ROS2 como la overlay o nuestro workspace:
```bash
source /opt/ros/jazzy/setup.bash
source /home/$USER/mounted/ws/install/setup.bash
```

En una de las terminales ejecutar el listener:
```bash
ros2 run ip_nodes listener
```

Y en la otra terminal ejecutar el talker:
```bash
ros2 run ip_nodes talker
```
Estamdo sobre la terminal del talker presionamos las flechas del teclado para mover remotamente el robot a través de la red wifi.

## 8. Ejecutar RVIZ2 
```bash
ros2 launch urdf_tutorial display.launch.py model:=/home/javierac/mounted/ws/src/sim/robot.urdf
 
```


ros2 run robot_state_publisher robot_state_publisher /home/javierac/mounted/ws/src/sim/robot.urdf

rviz2

ros2 topic pub --rate 10 /joint_states sensor_msgs/JointState "
header:
  stamp:
    sec: $(date +%s)
    nanosec: 0
  frame_id: ''
name: ['base_left_wheel_joint','base_right_wheel_joint']
position: [1.0, 0.0]
"

ros2 launch ip_nodes display.launch.py 

ros2 launch ip_nodes display.launch.py use_gui:=false

Ese error inicial de “No transform from [left_wheel] to [base_footprint]” no lo provoca tu .rviz, sino la propia cadena de TF en ROS 2: cuando arrancas, robot_state_publisher publica solo las transformaciones fijas (/tf_static), y las ruedas —al ser juntas continuous— necesitan un valor en /joint_states para generar sus TF dinámicas.

Hasta que entra al menos un mensaje con el nombre exacto de esas juntas (base_left_wheel_joint y base_right_wheel_joint) y un timestamp válido, esas transformaciones no existen y RViz se queja.

## 9. ARRANCAR PROYECTO
En el contenedor Docker
```bash
ros2 launch ip_nodes display.launch.py use_gui:=false
```

En la terminal SSH del EV3
```bash
python3 server_ev3.py
```

## más

jstest-gtk

pip3 install inputs --break-system-packages
El flag --break-system-packages ignora la restricción de PEP 668. Úsalo solo si sabes que no vas a romper dependencias del sistema. Para instalar en la versión de Python de ROS2

mando en docker: https://www.youtube.com/watch?v=uf4zOigzTFo&t=512s