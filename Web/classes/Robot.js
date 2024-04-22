
export class Robot{
    //---------------------------------------
    // CONSTRUCTOR
    //---------------------------------------
    /*
    especie: Txt
    estado: Txt
    descripcion: Txt
    */
    //---------------------------------------
    constructor(ip){
        this._ip = ip;
    }
    //---------------------------------------
    // SETTERS y GETTERS
    //---------------------------------------
    set_ip(ip){
        this._ip=ip;
    }
    get_ip(){
        return this._ip;
    }
    //---------------------------------------
    // button --> get_position()
    // Descripcion: Hace una llamada al Servidor para recoger su ubicación
    //---------------------------------------
    get_position(){
        //Llamar a Servidor
        //Fin
        console.log("get_position() hecho")
    }
    //---------------------------------------
    // METODOS
    //---------------------------------------

    //---------------------------------------
    // button, url_move:txt --> move_forward()
    // Descripcion: Hace una llamada al Servidor para moverse hacia adelante
    //---------------------------------------
    move_forward(url_move){
        //Llamar a Servidor
        fetch(url_move, {
            method: "POST",
            body: {'move':"forward"},
            headers:{
                "content-type": "application/json; charset=UTF-8",
            }
         })
         .then(info =>{
            // Code
            console.log("Move: forward")
            //console.log("Info: ")
            //console.log(info)
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("move_forward() hecho")
    }
    //---------------------------------------
    // button, url_move:txt --> move_backward()
    // Descripcion: Hace una llamada al Servidor para moverse hacia atras
    //---------------------------------------
    move_backward(url_move){
        //Llamar a Servidor
        fetch(url_move, {
            method: "POST",
            body: {'move':"backward"},
            headers:{
                "content-type": "application/json; charset=UTF-8",
            }
         })
         .then(info =>{
            // Code
            console.log("Move: backward")
            //console.log("Info: ")
            //console.log(info)
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("move_backward() hecho")
    }
    //---------------------------------------
    // button, url_move:txt --> move_right()
    // Descripcion: Hace una llamada al Servidor para girar a la derecha
    //---------------------------------------
    move_right(url_move){
        //Llamar a Servidor
        fetch(url_move, {
            method: "POST",
            body: {'move':"right"},
            headers:{
                "content-type": "application/json; charset=UTF-8",
            }
         })
         .then(info =>{
            // Code
            console.log("Move: right")
            //console.log("Info: ")
            //console.log(info)
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("move_right() hecho")
    }
    //---------------------------------------
    // button, url_move:txt --> move_left()
    // Descripcion: Hace una llamada al Servidor para girar a la izquierda
    //---------------------------------------
    move_left(url_move){
        //Llamar a Servidor
        fetch(url_move, {
            method: "POST",
            body: {'move':"left"},
            headers:{
                "content-type": "application/json; charset=UTF-8",
            }
         })
         .then(info =>{
            // Code
            console.log("Move: left")
            //console.log("Info: ")
            //console.log(info)
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("move_left() hecho")
    }
    //---------------------------------------
    // button, url_move:txt --> stop_move()
    // Descripcion: Hace una llamada al Servidor para detener el movimiento
    //---------------------------------------
    stop_move(url_move){
        //Llamar a Servidor
        fetch(url_move, {
            method: "POST",
            body: {'move':"stop"},
            headers:{
                "content-type": "application/json; charset=UTF-8",
            }
         })
         .then(info =>{
            // Code
            console.log("Move: stopped")
            //console.log("Info: ")
            //console.log(info)
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("stop_move() hecho")
    }
    //---------------------------------------
    // keypress --> console()
    // Descripcion: Según la flecha presionada, gestiona un movimiento u otro.
    // Cuando se deja de presionar, ejecuta stop_move()
    //---------------------------------------
    console(key){
        console.log("---------------------------")
        var url_move='http://localhost:5000/move'
        switch(key){
            case "ArrowDown":
                this.move_backward(url_move)
            break;
            case "ArrowUp":
                this.move_forward(url_move)
            break;
            case "ArrowLeft":
                this.move_left(url_move)
            break;
            case "ArrowRight":
                this.move_right(url_move)
            break;
            case "Stop":
                this.stop_move(url_move)
        }
    }
}