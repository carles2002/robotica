//-------------------------------------------------------------------------------------------------
// Autor: Arnau Soler Tomás
// Fichero: animalModal.js
// Descripción: Fichero encargado de gestionar el modal / popUp del animal.
//-------------------------------------------------------------------------------------------------

//------------------------------------------------
// IMPORTS
//------------------------------------------------
import { FakeVoice } from "./FakeVoice.js"
import { Animal } from "./Animal.js"
//------------------------------------------------
// Variables y Constantes Globales
//------------------------------------------------
let whichAnimal = localStorage.getItem("whichAnimal");
const fakevoice = new FakeVoice();


export class AnimalModal {
      constructor() { }

      //------------------------------------------------
      // METODOS
      //------------------------------------------------
      actualizarModal(especie) {
            console.log("actualizarModal() inicio")
            var animal = new Animal()
            animal.get_info(especie)

            setTimeout(function () {
                  var animal_name = document.getElementById("animal_name")
                  var animal_cartoon = document.getElementById("animal_cartoon")

                  var animal_description = document.getElementById("animal_description")
                  animal_description.innerText = animal.get_descripcion()

                  //set_image(animal)
            }, 1000)

      }

      set_image(animal) {
            var animal_image = document.getElementById("animal_image")
            animal_image.src = "../images/" + animal.get_especie() + ".png"
      }

      explicar_habitat() {
            habitat = animal.get_habitat()
            explicar(habitat)
      }

      explicar_descripcion() {
            descripcion = animal.get_descripcion()
            explicar(descripcion)
      }

      explicar_comida() {
            comida = animal.get_comida()
            explicar(comida)
      }

      explicar(texto) {
            fakevoice.voice.speech(texto)
      }
}
//------------------------------------------------

