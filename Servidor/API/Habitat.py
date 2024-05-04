import os

class Habitat:
    def __init__(self,habitat):
        self._habitat=habitat
        return
    #---------------------------------------------------
    # GETTER
    #---------------------------------------------------
    def get_habitat(self):
        return self._habitat
    #---------------------------------------------------
    # SETTER
    #---------------------------------------------------
    def set_habitat(self,habitat):
        self._habitat=habitat
    #---------------------------------------------------
    # METODOS
    #---------------------------------------------------

    #---------------------------------------------------
    # habitat:Txt --> ir()
    # Descripción: Método que dependiendo del habitat, el robot
    # ejecutará la orden de "Mover a un punto" a esa habitat en concreto
    #---------------------------------------------------
    def ir(self):
        habitat = self._habitat
        try:
            print("Llamando al fichero "+habitat+".bash")
            os.system("bash ../comandos/ir_a/"+habitat+".bash")
            print("ir() hecho")
            return
        except:
            raise ValueError("Habitat no encontrada")
            return