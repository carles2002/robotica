
export class Animal{
    //---------------------------------------
    // CONSTRUCTOR
    //---------------------------------------
    /*
    especie: Txt
    estado: Txt
    descripcion: Txt
    */
    //---------------------------------------
    constructor(especie,descripcion,caracteristicas,habitat,comida,estado){
        this._especie = especie;
        this._descripcion = descripcion;
        this._caracteristicas = caracteristicas;
        this._habitat = habitat;
        this._comida = comida;
        this._estado = estado;
    }
    //---------------------------------------
    // SETTERS y GETTERS
    //---------------------------------------
    set_especie(especie){
        this._especie=especie;
    }
    get_especie(){
        return this._especie;
    }
    //--------
    set_descripcion(descripcion){
        this._descripcion=descripcion;
    }
    get_descripcion(){
        return this._descripcion;
    }
    //--------
    set_caracteristicas(caracteristicas){
        this._caracteristicas=caracteristicas;
    }
    get_caracteristicas(){
        return this._caracteristicas;
    }
    //--------
    set_habitat(habitat){
        this._habitat=habitat;
    }
    get_habitat(){
        return this._habitat;
    }
    //--------
    set_comida(comida){
        this._comida=comida;
    }
    get_comida(){
        return this._comida;
    }
    //--------
    set_estado(estado){
        this._estado=estado;
    }
    get_estado(){
        return this._estado;
    }
    //--------
    //---------------------------------------
    // METODOS
    //---------------------------------------
    get_info(especie){
        fetch("http://localhost:5000/get_animal_info", {
            method: "POST",
            body: JSON.stringify({'especie':especie}),
            headers:{
                "Content-Type": "application/json",
            }
         })
         .then(info =>{
            // Code
            info.json().then(data =>{
                this.actualizar(data)
            })
         })
         .catch(error =>{
            // catch error
            console.log("Error: "+error)
         });
        //Fin
        console.log("get_info() hecho")
    }

    actualizar(data){
        this.set_especie(data["_especie"])
        this.set_descripcion(data["_descripcion"])
        this.set_caracteristicas(data["_caracteristicas"])
        this.set_habitat(data["_habitat"])
        this.set_comida(data["_comida"])
        this.set_estado(data["_estado"])
    }
}