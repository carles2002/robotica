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

        os.system("bash ../comandos/movimiento/adelante.bash")
        #orden="delante"
        #os.system("bash ../comandos/movimiento/move.bash")
        #os.system("bash move "+orden)
        return
    #------------------------------------------------------------
    # move_backward()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_backward(self):
        #Mover
        os.system("bash ../comandos/movimiento/atras.bash")
        return
    #------------------------------------------------------------
    # move_right()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_right(self):
        #Mover
        os.system("bash ../comandos/movimiento/derecha.bash")
        return
    #------------------------------------------------------------
    # move_left()
    # Descripcion: Mueve a una velocidad constante hacia adelante
    #------------------------------------------------------------
    def move_left(self):
        #Mover
        os.system("bash ../comandos/movimiento/izquierda.bash")
        return
    #------------------------------------------------------------
    # stop_move()
    # Descripcion: Detiene el movimiento del robot
    #------------------------------------------------------------
    def stop_move(self):
        #Parar
        os.system("bash ../comandos/movimiento/stop.bash")
        return
    #------------------------------------------------------------
    # console()
    # Descripcion: Detiene el movimiento del robot
    #------------------------------------------------------------
    def console(self, move):
        print("Robot_console")
        if(move=="left"):
            self.move_left()
        elif(move=="right"):
            self.move_right()
        elif(move=="backward"):
            self.move_backward()
        elif(move=="forward"):
            self.move_forward()
        else:
            return "Error 404 - No move"
    #------------------------------------------------------------
    # stop_move()
    # Descripcion: 
    # - Inicia el paquete web_video_server
    # - Se subscribe al topic /imagen
    #------------------------------------------------------------
    def camara_web(self):
        os.system("gnome-terminal -- bash -c '../comandos/iniciar_webserver.bash; exec bash'")
        os.system("gnome-terminal -- bash -c '../comandos/subscribirse_imagen.bash; exec bash'")
        return