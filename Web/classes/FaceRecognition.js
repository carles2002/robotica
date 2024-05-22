export class FaceRecognition {

      constructor() {
            this.status = false
      }

      //-------------------------------------------------------------
      // click run_recognition()
      //-------------------------------------------------------------
      async run_recognition() {
            console.log("llamando al servidor")
            //Llamar a Servidor
            await fetch("http://localhost:5000/face_recognition", {
                  headers: {
                        "Content-Type": "application/json",
                  }
            })
                  .then(info => {
                        // Code
                        console.log("face_recognition: ")
                        if (info.ok) {
                              console.log("Status ok")
                              this.status = true
                        }
                  })
                  .catch(error => {
                        // catch error
                        console.log("Error: " + error)
                  });
            //Fin
            console.log("run_recognition() hecho")
            return
      }
}