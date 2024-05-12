export class Voice{
    //------------------------------------------------------------------
    // Constructor --> Voice
    //------------------------------------------------------------------
    constructor(){
        this.recognition = new webkitSpeechRecognition();
        this.recognition.continuous = true;
        this.recognition.lang = 'es-ES';
        this.recognition.interimResult = false;
    }
    //------------------------------------------------------------------
    // Voice --> listen()
    // Empieza a escuchar
    //------------------------------------------------------------------
    speech(text){
        //Declarar constante
        const speech = new SpeechSynthesisUtterance(text);
        //Ajustes
        speech.volume = 1;      //Volumen
        speech.rate = 0.75;     //Velocidad de reproducción
        speech.pitch = 1.2;     //Tono de voz
        speech.lang = 'es-ES'   //Idioma
        //Hablar
        window.speechSynthesis.speak(speech);
    }
    //------------------------------------------------------------------
    // Voice --> listen()
    // Empieza a escuchar
    //------------------------------------------------------------------
    listen(){
        console.log("Escuchando")
        this.recognition.start()
    }
    //------------------------------------------------------------------
    // recognition:SpeechRecognition --> stopListen()
    // Detiene la escucha
    //------------------------------------------------------------------
    stopListen(){
        console.log("Deteniendo Escucha")
        this.recognition.abort();
    }

}
//----------------------------------------------------------------------
/*
Notas:
· Si se usa desde una virtualbox, ir a Dispositivos > Audio > tener activas ambas opciones
· Hay que tener la posibilidad del permiso de Micrófono
· Esta clase es funcional para todos los buscadores hasta el momento excepto:
Firefox
Opera GX

Y derivados de estos
*/
