
export class Roslib {
      constructor() {
            this.data = {
                  // ros connection
                  ros: null,
                  rosbridge_address: 'ws://127.0.0.1:9090/',
                  connected: false
            }
      }
      //----------------------------------------------------------------------------------------------
      // launchWebSocket()
      // Descripcion: Método que llama al servidor para lanzar el servicio del Web Socket de Roslibjs
      //----------------------------------------------------------------------------------------------
      launchWebSocket() {
            fetch("http://localhost:5000/launchWebSocket", {
                  headers: {
                        "Content-Type": "application/json",
                  }
            })
                  .then(info => {
                        // Code
                        console.log("launchWebSocket() servidor hecho")
                        //console.log("Info: ")
                        //console.log(info)
                  })
                  .catch(error => {
                        // catch error
                        console.log("Error: " + error)
                  });
      }
      //----------------------------------------------------------------------------------------------
      // data --> connect() --> VoF
      // Descripcion: Método que llama al servidor para lanzar el servicio del Web Socket de Roslibjs
      //----------------------------------------------------------------------------------------------
      async connect() {
            if (this.data.connected == false) {
                  await this.launchWebSocket()
            }
            this.data.ros = new ROSLIB.Ros({
                  url: this.data.rosbridge_address
            })

            // Define callbacks
            this.data.ros.on("connection", () => {
                  this.data.connected = true
                  console.log("Conexion con ROSBridge correcta")
            })
            this.data.ros.on("error", (error) => {
                  console.log("Se ha producido algun error mientras se intentaba realizar la conexion")
                  console.log(error)
            })
            this.data.ros.on("close", () => {
                  this.data.connected = false
                  console.log("Conexion con ROSBridge cerrada")
            })
      }
      //----------------------------------------------------------------------------------------------
      // data --> disconnect()
      // Descripcion: Método para desconectar el servicio del Web Socket de Roslibjs
      //----------------------------------------------------------------------------------------------
      disconnect() {
            this.data.ros.close()
            this.data.connected = false
      }
      //----------------------------------------------------------------------------------------------
      // escucharposicion()
      // Descripcion: Método para conocer la posición actual del Robot mediante el topic /odom
      //----------------------------------------------------------------------------------------------
      escucharposicion() {
            //this.publicarOdom()
            console.log("escucharposicion()")
            let topic_odom = new ROSLIB.Topic({
                  ros: this.data.ros,
                  name: '/odom',
                  messageType: 'nav_msgs/msg/Odometry'
            })
            
            //console.log(topic_odom)
            topic_odom.subscribe((message) => {
                  console.log("Se está suscribiendo...")
                  this.data.position = message.pose.pose.position
                  let pos_x = this.data.position.x.toFixed(2)
                  let pos_y = this.data.position.y.toFixed(2)

                  console.log("Posición X: " + pos_x)
                  console.log("Posición Y: " + pos_y)

                  this.disconnect()
            })
      }

      publicarOdom(){
            let topic = new ROSLIB.Topic({
                  ros: this.data.ros,
                  name: '/odom',
                  messageType: 'nav_msgs/msg/Odometry'
              })
              let message = new ROSLIB.Message({
                  pose:{pose:{position:{x:2.0,y:3.0}}}
              })
              topic.publish(message)
      }
}