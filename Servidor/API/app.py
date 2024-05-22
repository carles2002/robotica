from flask import Flask, request
from flask_cors import CORS
import os

from Robot import Robot
from Habitat import Habitat

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

default_ip = "192.168.0.64"
robot = Robot(default_ip)

@app.route('/')
def index():
    return "¡Hola Mundo!"
#-----------------------------------------------------------------
# move --> move()
# Descripcion: funcion para mover o detener al robot
#-----------------------------------------------------------------
@app.route('/move',methods=['POST'])
def move():
    print("app move()")
    if(request.method == 'POST'):
        move = request.get_json()
        move = move['move']
        print(f"Move: {move}")
        if(move=="stop"):
            print("Deteniendo Movimiento")
            robot.stop_move()
            print("Detenido")
        else:
            robot.console(move)
            print("En movimiento")
        return ('',204)
#-----------------------------------------------------------------
# habitat --> ir()
# Descripcion: funcion para ir a un habitat
#-----------------------------------------------------------------
@app.route('/ir_a_habitat',methods=['POST'])
def ir():
    print("ir()")
    if(request.method == 'POST'):
        lugar = request.get_json()
        lugar = lugar['habitat']
        habitat = Habitat(lugar)
        habitat.ir()
        return ('',204)
    #ir
#-----------------------------------------------------------------
# __main__
# Descripcion: Para arrancar el puerto del servidor Flask
#-----------------------------------------------------------------
if __name__ == '__main__':
    app.run(debug=True, port=5000)
