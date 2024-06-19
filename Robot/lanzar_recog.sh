# Ejecutar el nodo publicador en una nueva terminal
gnome-terminal -- bash -c "ros2 run image_recognition image_recognition; exec bash"

# Ejecutar el nodo suscriptor en otra nueva terminal
gnome-terminal -- bash -c "ros2 run image_recognition image_recognition_subscriber; exec bash"