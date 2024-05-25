//-------------------------------------------------------------------------------------------------
// Autor: Arnau Soler Tomás
// Fichero: admin.js
// Descripción: Fichero encargado de gestionar la página del administrador.
//-------------------------------------------------------------------------------------------------

//------------------------------------------------
// IMPORTS
//------------------------------------------------
import { AnimalModal } from "../classes/AnimalModal.js"
import { Robot } from "../classes/Robot.js"
import { FakeVoice } from "../classes/FakeVoice.js"
import { Habitat } from "../classes/Habitat.js"
import { FaceRecognition } from "../classes/FaceRecognition.js"
//------------------------------------------------
// VARIABLES GLOBALES
//------------------------------------------------
let isAdmin = localStorage.getItem("isAdmin");
if (isAdmin == 'true') {
    console.log("redireccionando...")
    redirect_admin()
}

var lugar = null;
var habitat = null;
const animalModal = new AnimalModal()
//------------------------------------------------
// MICROFONO ROBOT
//------------------------------------------------
const btn_microfono = document.getElementById("btn_microfono");
const fakevoice = new FakeVoice();
var micro_pressed = true

btn_microfono.addEventListener("click", function () {
    if (micro_pressed) {
        micro_pressed = false
        fakevoice.voice.listen()
    }
    else {
        micro_pressed = true
        fakevoice.voice.stopListen()
    }
});
//------------------------------------------------
// HABLAR ROBOT
//------------------------------------------------
function ir_a(fakevoice, lugar, habitat) {
    lugar = "Vamos a ver a " + lugar
    fakevoice.voice.speech(lugar)
    habitat.ir()
}

fakevoice.voice.recognition.onresult = (event) => {
    micro_pressed = true
    fakevoice.voice.stopListen()
    var text = event.results[event.results.length - 1][0].transcript;
    text = text.toLowerCase()
    console.log("Text:" + text)

    if (text.includes("ver") || text.includes("ir a")) {

        if (text.includes("león") || text.includes("leones")) {
            //Mover al punto de leones
            console.log("Iendo a los leones")
            lugar = " los leones"
            habitat = new Habitat("leon")
            ir_a(fakevoice, lugar, habitat)
        }
        else if (text.includes("mono" || "monos")) {
            //Mover al punto de los monos
            console.log("Iendo a los monos")
            lugar = " los monos"
            habitat = new Habitat("mono")
            ir_a(fakevoice, lugar, habitat)
        }
        else if (text.includes("jirafa" || "jirafas")) {
            //Mover al punto de las jirafa
            console.log("Iendo a las jirafas")
            lugar = " las jirafas"
            habitat = new Habitat("jirafa")
            ir_a(fakevoice, lugar, habitat)
        }
    }
}
//------------------------------------------------
// EVENTLISTENERS
//------------------------------------------------

// Escuchar boton acceso admin
var btn_go_admin = document.getElementById("btn_admin")
btn_go_admin.addEventListener("click", admin_site)

//------------
// ANIMALES
//------------

// Escuchar boton león
document.getElementById("btn_ir_leon").addEventListener("click", function () {
    const fakevoice = new FakeVoice();

    lugar = " los leones"
    habitat = new Habitat("leon")
    ir_a(fakevoice, lugar, habitat)

    localStorage.setItem("whichAnimal", "leon");
    animalModal.actualizarModal("leon")
});
// Escuchar boton mono
document.getElementById("btn_ir_mono").addEventListener("click", function () {
    const fakevoice = new FakeVoice();

    lugar = " los monos"
    habitat = new Habitat("mono")
    ir_a(fakevoice, lugar, habitat)

    localStorage.setItem("whichAnimal", "mono");
    animalModal.actualizarModal("mono")
});
// Escuchar boton jirafa
document.getElementById("btn_ir_jirafa").addEventListener("click", function () {
    const fakevoice = new FakeVoice();

    lugar = " las jirafas"
    habitat = new Habitat("jirafa")
    ir_a(fakevoice, lugar, habitat)

    localStorage.setItem("whichAnimal", "jirafa");
    animalModal.actualizarModal("jirafa")
});
//-------------
// BOTONES MODAL
// Escuchar boton descripción
var animal_description_voice = document.getElementById("animal_description_voice")
animal_description_voice.addEventListener("click", function () {
    animalModal.explicar_descripcion()
    animalModal.explicar_comida()
})
// Escuchar boton habitat
var animal_habitat = document.getElementById("animal_habitat")
animal_habitat.addEventListener("click", function () {
    animalModal.explicar_habitat()
})
//------------------------------------------------
// ADMINISTRADOR
//------------------------------------------------
async function admin_site() {
    console.log("admin_site()")
    var fr = new FaceRecognition()

    await fr.run_recognition()
    console.log("fr.status")
    console.log(fr.status)
    var status = fr.status
    if (status) {
        //cambiar el localStorage
        localStorage.setItem("isAdmin", true);
        //redireccionar a admin
        redirect_admin()
    }
    else {
        console.log("Se ha abortado el proceso")
    }
    return
}

function redirect_admin() {
    //redirecciona al admin
    location.href = "admin.html";
    return
}
