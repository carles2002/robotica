export class Habitat{
    //---------------------------------------
    // CONSTRUCTOR
    //---------------------------------------
    /*
    habitat: Txt
    */
    //---------------------------------------
    constructor(habitat){
        this._habitat = habitat;
    }
    //---------------------------------------
    // SETTERS y GETTERS
    //---------------------------------------
    set habitat(habitat){
        this._habitat = habitat;
    }
    get habitat(){
        return this._habitat;
    }

    //--------------------------------------------------------------
    // habitat:Txt --> ir() --> API
    // Descripción: Método Fake de ir()
    //--------------------------------------------------------------
    ir(){
        //Llamar a Servidor
    fetch("http://localhost:5000/ir_a_habitat", {
        method: "POST",
        body: JSON.stringify({'habitat':this._habitat}),
        headers:{
            "Content-Type": "application/json",
        }
     })
     .then(info =>{
        // Code
        console.log("ir() servidor hecho")
        //console.log("Info: ")
        //console.log(info)
     })
     .catch(error =>{
        // catch error
        console.log("Error: "+error)
     });
    //Fin
    console.log("ir() hecho")
    }
}