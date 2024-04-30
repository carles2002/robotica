from flask import Flask, request
from flask_cors import CORS
import os

from Robot import Robot

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

default_ip = "192.168.0.64"
robot = Robot(default_ip)

@app.route('/')
def index():
    return "¡Hola Mundo!"
#-----------------------------------------------------------------
# ip --> ip_robot()
# Descripcion: funcion para cambiar la IP al robot
#-----------------------------------------------------------------
@app.route('/ip_robot',methods=['POST'])
def ip_robot():
    print("app ip_robot()")
    if(request.method == 'POST'):
        ip = request.form.get('ip')
        #robot = Robot(ip)
        #Guardar
        #robot.save()
        print(ip)
        return ('',204)

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
    
@app.route('/connect')
def connect():
    print("Conectando a ubuntu@192.168.0.64")
    os.system("bash ../comandos/conectar.bash")

    return "ok"

if __name__ == '__main__':
    app.run(debug=True, port=5000)
