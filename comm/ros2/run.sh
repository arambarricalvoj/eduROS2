xhost +local:*
docker run -e DISPLAY=$DISPLAY \
           -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
           -v /home/$USER/Documents/eduros2_ev3/comm/ros2/mounted:/home/$USER/mounted/ \
           -v /dev/input:/dev/input \
           --device-cgroup-rule='c 13:* rmw' \
           -p 5000:5000/udp \
           -p 5001:5001/udp \
           -p 5002:5002/udp \
           --device /dev/dri:/dev/dri \
           --device /dev/input:/dev/input \
           -it \
           --gpus all \
           --name eduros2_ev3_jazzy_v1.1_urdf_tutorial \
           arambarricalvoj/eduros2_ev3:jazzy_v1.1_urdf_tutorial
