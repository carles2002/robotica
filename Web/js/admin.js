//-------------------------------------------------------------------------------------------------
// Autor: Arnau Soler Tomás
// Fichero: admin.js
// Descripción: Fichero encargado de gestionar la página del administrador. Tenemos:
// · Información del Robot
// · Cambiar IP del Robot
// · Consola para mover al Robot
// · Pantalla para ver lo que ve el Robot
//-------------------------------------------------------------------------------------------------

//------------------------------------------------
// NOTAS
// En esta versión:
// · No hay pantalla
// · La IP se guarda mediante la sesión Local (localstorage)
// · Es posible controlar el movimiento con las flechas del teclado
//------------------------------------------------

//------------------------------------------------
// IMPORTS
//------------------------------------------------
import "../classes/Robot.js"
import { Robot } from "../classes/Robot.js"
//------------------------------------------------
// Variables y Constantes Globales
//------------------------------------------------
var default_ip = "127.0.0.1"
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
// EVENTLISTENERS
//------------------------------------------------

// Escuchar cambio de IP
document.getElementById('btn_robotIp').addEventListener("click", cambiar_ip);
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
//------------------------------------------------
// MOVER ROBOT
//------------------------------------------------

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