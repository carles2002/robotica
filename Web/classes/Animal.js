
class Animal{
    //---------------------------------------
    // CONSTRUCTOR
    //---------------------------------------
    /*
    especie: Txt
    estado: Txt
    descripcion: Txt
    */
    //---------------------------------------
    constructor(especie,estado,descripcion){
        this._especie = especie;
        this._estado = estado;
        this._descripcion = descripcion;
    }
    //---------------------------------------
    // SETTERS y GETTERS
    //---------------------------------------
    set especie(especie){
        this._especie=especie;
    }
    get _especie(){
        return this._especie;
    }

    set estado(estado){
        this._estado=estado;
    }
    get estado(){
        return this._estado;
    }

    set descripcion(descripcion){
        this._descripcion=descripcion;
    }
    get descripcion(){
        return this._descripcion;
    }
}