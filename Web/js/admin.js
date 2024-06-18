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
import { Roslib } from "../classes/Roslib.js"
//------------------------------------------------
// Variables y Constantes Globales
//------------------------------------------------
let isAdmin = localStorage.getItem("isAdmin");
if (isAdmin == 'false') { redirect_user() }

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

var roslib = new Roslib()

//------------------------------------------------
// EVENTLISTENERS
//------------------------------------------------

// Escuchar Cerrar Sesión
var btn_admin_inicio = document.getElementById("btn_admin_inicio")
btn_admin_inicio.addEventListener("click", cerrar_sesion)

// Escuchar Conectar Camara Web
var btn_camara_web = document.getElementById("btn_camara_web")
btn_camara_web.addEventListener("click",abrir_camara_robot)

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
                console.log(event.target.parentElement.value)
                robot.console(event.target.parentElement.value)
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

// Escuchar posición actual
let btn_ubic_robot = document.getElementById("btn_ubic_robot");
btn_ubic_robot.addEventListener('click', (event) => {
    if (roslib.data.connected == false){
        roslib.connect()
        setTimeout(function () {
            roslib.escucharposicion()
      }, 1000)
    }
    else {
        roslib.escucharposicion()
        //roslib.disconnect()
    }
});
//------------------------------------------------
// METODOS
//------------------------------------------------
let activar_camara=true
function abrir_camara_robot(){
    if(activar_camara){
        robot.camara_web()
        activar_camara=false
        let iframe_camera_web = document.getElementById("iframe_camera_web")
        iframe_camera_web.src = "http://0.0.0.0:8080/stream?topic=/image&type=mjpeg&width=300&height=200"
    }
    setTimeout(function () {
        iframe_camera_web.contentDocument.location.reload(true);
    }, 2000)
}

function cerrar_sesion(){
      //cambiar el localStorage
      localStorage.setItem("isAdmin", false);
      //redireccionar a user
      redirect_user()
}

function redirect_user() {
    //redirecciona al admin
    location.href = "landing.html";
    return
}
