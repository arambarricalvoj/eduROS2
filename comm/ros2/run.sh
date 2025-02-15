xhost +local:*
docker run -e DISPLAY=$DISPLAY \
           -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
           -v /home/$USER/Documents/tfg/tfg_ev3/comm/ros2/mounted:/home/$USER/mounted/ \
           -it \
           --gpus all \
           --name ros_jazzy_instance ros2_mvsim:latest
