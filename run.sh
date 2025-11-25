xhost +local:*
docker run -e DISPLAY=$DISPLAY \
           -e USER=$USER \
           -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
           -v ./eduros2_lego:/home/$USER/eduros2_lego/ \
           -v /dev/input:/dev/input \
           --device-cgroup-rule='c 13:* rmw' \
           -p 5000:5000/udp \
           -p 5001:5001/udp \
           -p 5002:5002/udp \
           -p 5003:5003/udp \
           -p 5004:5004/udp \
           --device /dev/dri:/dev/dri \
           --device /dev/input:/dev/input \
           -it \
           --rm \
           --gpus all \
           --name eduros2_control_inteligente \
           arambarricalvoj/eduros2_ev3:control_inteligente
