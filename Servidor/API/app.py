from flask import Flask, request
from flask_cors import CORS

import Robot

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'

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
        move = request.args
        print(f"Move: {move}")
        if(move=="stop"):
            print("Deteniendo Movimiento")
        else:
            print("En movimiento")
        return ('',204)
    

if __name__ == '__main__':
    app.run(debug=True, port=5000)
