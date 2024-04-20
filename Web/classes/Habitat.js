class Habitat{
    //---------------------------------------
    // CONSTRUCTOR
    //---------------------------------------
    /*
    habitat: Txt
    animales: <Animal> 
    */
    //---------------------------------------
    constructor(habitat,animales){
        this._habitat = habitat;
        this._animales = animales;
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

    set animales(animales){
        this._animales = animales;
    }
    get animales(){
        return this._animales;
    }
}