import os

class Robot:
    def __init__(self,ip):
        self._ip=ip
    
    def get_ip(self):
        return self._ip
    def set_ip(self,ip):
        self._ip=ip

    #---------------------------------------
    # get_position() --> position
    # Descripcion: Hace una llamada al Servidor para recoger su ubicación
    #---------------------------------------
    def get_position(self):
        position = "undefined"
        #Recoge la odometria con un mensaje de tipo Pose

        #Devuelve la posición del robot
        return position
    
    #------------------------------------------------------------
    # move_forward()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_forward(self):
        #Mover
        os.system("ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist '{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.1}}'")
        return
    #------------------------------------------------------------
    # move_backward()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_backward(self):
        #Mover
        return
    #------------------------------------------------------------
    # move_right()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_right(self):
        #Mover
        return
    #------------------------------------------------------------
    # move_left()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_left(self):
        #Mover
        return
    #------------------------------------------------------------
    # stop_move()
    # Descripcion: Detiene el movimiento del robot
    #------------------------------------------------------------
    def stop_move(self):
        #Parar
        os.system("ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist '{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}'")
        return