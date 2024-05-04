//-------------------------------------------------------------------------------------------------
// Autor: Arnau Soler Tomás
// Fichero: admin.js
// Descripción: Fichero encargado de gestionar la página del administrador. Tenemos:
// · Información del Robot
// · Cambiar IP del Robot
// · Consola para mover al Robot
// · Pantalla para ver lo que ve el Robot
// · Comandos por voz
// · Respuesta del robot
//-------------------------------------------------------------------------------------------------

//------------------------------------------------
// NOTAS
// En esta versión:
// · No hay pantalla
// · La IP se guarda mediante la sesión Local (localstorage)
// · Es posible controlar el movimiento con las flechas del teclado
// · Se importa una clase para interactuar con comandos de voz con el robot
//------------------------------------------------

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

fakevoice.voice.recognition.onresult = (event) => {
    micro_pressed = true
    fakevoice.voice.stopListen()
    var text = event.results[event.results.length - 1][0].transcript;
    text = text.toLowerCase()
    console.log("Text:" + text)
    
    var lugar = "Vamos a ver a"
    var habitat = null;

    if(text.includes("ver")||text.includes("ir a")){

        if(text.includes("león")||text.includes("leones")){
            //Mover al punto de leones
            console.log("Iendo a los leones")
            lugar+=" los leones"
            fakevoice.voice.speech(lugar)
    
            habitat = new Habitat("leon")
            habitat.ir()
        }
        else if(text.includes("mono"||"monos")){
            //Mover al punto de los monos
            console.log("Iendo a los monos")
            lugar+=" los monos"
            fakevoice.voice.speech(lugar)
            
            habitat = new Habitat("mono")
            habitat.ir()
        }
        else if(text.includes("jirafa"||"jirafas")){
            //Mover al punto de las jirafa
            console.log("Iendo a las jirafas")
            lugar+=" las jirafas"
            fakevoice.voice.speech(lugar)
            
            habitat = new Habitat("jirafa")
            habitat.ir()
        }
    }
}
//------------------------------------------------
// EVENTLISTENERS
//------------------------------------------------

// Escuchar cambio de IP
document.getElementById('btn_robotIp').addEventListener("click", cambiar_ip);

// Escuchar conectar
document.getElementById("btn_robotConnect").addEventListener("click", function(){
    robot.connect()
 });

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
//------------------------------------------------
// INFORMACIÓN ROBOT
//------------------------------------------------
function informacion() {
    var span_rip = document.getElementById("span_rip")
    var span_rub = document.getElementById("span_rub")

    span_rip.innerHTML = "Robot IP:"+robot.get_ip()
    span_rub.innerHTML = "Ubicación:"+robot.get_position()
}
informacion()

//---------------------------------------
// METODOS
//---------------------------------------

//---------------------------------------
// form --> cambiar_ip()
// Descripcion: Recoge una nueva IP de la página del admin y la cambia por la antigua
//---------------------------------------
function cambiar_ip() {
    //recoger ip del formulario
    var ip = document.getElementById("inputRobotIp").value
    //ip = "127.0.0.1" //Por defecto de la VirtualBox
    console.log("cambiar_ip Inicio con Ip: " + ip)
    //cambiar la ip por la del robot
    robot.set_ip(ip)
    localStorage.setItem("robot_ip", ip);

    //Llamar a Servidor
    fetch("http://localhost:5000/ip_robot", {
        method: "POST",
        body: { 'ip': ip },
        headers: {
            "content-type": "application/json; charset=UTF-8",
        }
    })
        .then(info => {
            // Code
            console.log("Cambio de IP")
            //console.log("Info: ")
            //console.log(info)
        })
        .catch(error => {
            // catch error
            console.log("Error: " + error)
        });

    console.log("Fake cambiar_ip() hecho")
    informacion()
    //Fin
}