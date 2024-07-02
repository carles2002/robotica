from flask import Flask, request, jsonify
from flask_cors import CORS
import os

from Robot import Robot
from Habitat import Habitat
from FaceRecognition import FaceRecognition
from Animal import Animal

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
    return ('',400)
    #ir
#-----------------------------------------------------------------
# face_recognition() --> '204'||'400'
# Descripcion: funcion para reconocer un rostro
#-----------------------------------------------------------------
@app.route('/face_recognition')
def face_scan():
    print("face_recognition()")
    fr = FaceRecognition()
    status=fr.run_recognition()
    del fr
    
    if(status):
        return ('ok',204)
    return ('not ok',400)
#-----------------------------------------------------------------
# Animal --> get_animal_info() --> info:Txt
# Descripcion: funcion para reconocer un rostro
#-----------------------------------------------------------------
@app.route('/get_animal_info',methods=['POST'])
def get_animal_info():
    if(request.method == 'POST'):
        especie = request.get_json()
        especie = especie['especie']
        animal = Animal()
        animal.get_info(especie)
        
        return jsonify(animal.__dict__)
#-----------------------------------------------------------------
# cam_web_server() --> '204'||'400'
# Descripcion: funcion para reconocer un rostro
#-----------------------------------------------------------------
@app.route('/cam_web_server')
def cam_web_server():
    print("cam_web_server()")
    robot.camara_web()
    
    return ('',204)
#-----------------------------------------------------------------
# launchWebSocket() --> '204'||'400'
# Descripcion: funcion para lanzar el WebSocket de Roslib
#-----------------------------------------------------------------
@app.route('/launchWebSocket')
def launchWebSocket():
    print("launchWebSocket()")
    #os.system("export ROS_DOMAIN_ID=5")
    #os.system("ros2 topic list")
    os.system("bash comandos/rosbridge.bash")
    return ('',204)
#-----------------------------------------------------------------
# __main__
# Descripcion: Para arrancar el puerto del servidor Flask
#-----------------------------------------------------------------
if __name__ == '__main__':
    app.run(debug=True, port=5000)
