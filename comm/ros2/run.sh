xhost +local:*
docker run -e DISPLAY=$DISPLAY \
           -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
           -v /home/$USER/Documents/eduROS2_ev3/tfg_ev3/comm/ros2/mounted:/home/$USER/mounted/ \
           -it \
           --gpus all \
           --name eduros2_ev3_jazzy_v1.0 arambarricalvoj/eduros2_ev3:jazzy_v1.0
