import { Voice } from "../../Servidor/API/Voice.js"

export class FakeVoice{
    //------------------------------------------------------------------
    // Constructor --> FakeVoice
    //------------------------------------------------------------------
    constructor(){
        this.voice = new Voice()
    }
    //------------------------------------------------------------------
    // FakeVoice --> listen()
    // Empieza a escuchar
    //------------------------------------------------------------------
    speech(text){
        this.voice.speech(text)
    }
    //------------------------------------------------------------------
    // FakeVoice --> listen()
    // Empieza a escuchar
    //------------------------------------------------------------------
    listen(){
        console.log("Escuchando")
        this.voice.listen()
    }
    //------------------------------------------------------------------
    // FakeVoice --> stopListen()
    // Detiene la escucha
    //------------------------------------------------------------------
    stopListen(){
        console.log("Deteniendo Escucha")
        this.voice.stopListen()
    }

}
