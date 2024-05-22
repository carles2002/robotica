//-------------------------------------------------------------------------------------------------
// Autor: Arnau Soler Tomás
// Fichero: admin.js
// Descripción: Fichero encargado de gestionar la página del administrador.
//-------------------------------------------------------------------------------------------------

//------------------------------------------------
// IMPORTS
//------------------------------------------------
import "../classes/Robot.js"
import { Robot } from "../classes/Robot.js"
import { FakeVoice } from "../classes/FakeVoice.js"
import { Habitat } from "../classes/Habitat.js"
//------------------------------------------------
// Variables y Constantes Globales
//------------------------------------------------
var default_ip = "192.168.0.64"
const localStorageIp = localStorage.getItem("robot_ip")

var key_pressed = false
var mouse_pressed = false
var input_valido = ["ArrowDown", "ArrowUp", "ArrowLeft", "ArrowRight"]

var robot = new Robot(default_ip)

if (localStorageIp) {
    robot.set_ip(localStorageIp)
}

console.log("Robot")
console.log(robot)

//------------------------------------------------
// MICROFONO ROBOT
//------------------------------------------------
const btn_microfono = document.getElementById("btn_microfono");
const fakevoice = new FakeVoice();
var micro_pressed = true

btn_microfono.addEventListener("click", function(){
    if(micro_pressed){
        micro_pressed = false
        fakevoice.voice.listen()
    }
    else{
        micro_pressed = true
        fakevoice.voice.stopListen()
    }
});
//------------------------------------------------
// HABLAR ROBOT
//------------------------------------------------
function ir_a(fakevoice, lugar, habitat){
      lugar = "Vamos a ver a "+lugar
      fakevoice.voice.speech(lugar)
      habitat.ir()
}

fakevoice.voice.recognition.onresult = (event) => {
    micro_pressed = true
    fakevoice.voice.stopListen()
    var text = event.results[event.results.length - 1][0].transcript;
    text = text.toLowerCase()
    console.log("Text:" + text)
    
    var lugar = null;
    var habitat = null;

    if(text.includes("ver")||text.includes("ir a")){

        if(text.includes("león")||text.includes("leones")){
            //Mover al punto de leones
            console.log("Iendo a los leones")
            lugar=" los leones"
            habitat = new Habitat("leon")
            ir_a(fakevoice,lugar,habitat)
        }
        else if(text.includes("mono"||"monos")){
            //Mover al punto de los monos
            console.log("Iendo a los monos")
            lugar=" los monos"
            habitat = new Habitat("mono")
            ir_a(fakevoice,lugar,habitat)
        }
        else if(text.includes("jirafa"||"jirafas")){
            //Mover al punto de las jirafa
            console.log("Iendo a las jirafas")
            lugar=" las jirafas"
            habitat = new Habitat("jirafa")
            ir_a(fakevoice,lugar,habitat)
        }
    }
}
//------------------------------------------------
// EVENTLISTENERS
//------------------------------------------------

// Escuchar KeyPad
document.addEventListener('keydown', (event) => {
    if (!key_pressed) {
        if (input_valido.includes(event.code))
            key_pressed = true
        robot.console(event.code)
    }
});
document.addEventListener('keyup', (event) => {
    if (key_pressed) {
        key_pressed = false
        robot.console("Stop")
    }
});


// Escuchar Botones de Movimiento
function btn_listen() {
    var btn_move_list = document.getElementsByClassName("btn_move")
    for (var i = 0; i < btn_move_list.length; i++) {
        btn_move_list[i].addEventListener('mousedown', (event) => {
            if (!mouse_pressed) {
                mouse_pressed = true
                robot.console(event.target.value)
            }
            btn_listen()
        });
        btn_move_list[i].addEventListener('mouseup', (event) => {
            if (mouse_pressed) {
                mouse_pressed = false
                robot.console("Stop")
            }
            btn_listen()
        });
    }
}
btn_listen()