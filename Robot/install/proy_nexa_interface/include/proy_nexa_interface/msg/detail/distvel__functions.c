// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from proy_nexa_interface:msg/Distvel.idl
// generated code does not contain a copyright notice
#include "proy_nexa_interface/msg/detail/distvel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
proy_nexa_interface__msg__Distvel__init(proy_nexa_interface__msg__Distvel * msg)
{
  if (!msg) {
    return false;
  }
  // distancia
  // velocidad
  return true;
}

void
proy_nexa_interface__msg__Distvel__fini(proy_nexa_interface__msg__Distvel * msg)
{
  if (!msg) {
    return;
  }
  // distancia
  // velocidad
}

bool
proy_nexa_interface__msg__Distvel__are_equal(const proy_nexa_interface__msg__Distvel * lhs, const proy_nexa_interface__msg__Distvel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distancia
  if (lhs->distancia != rhs->distancia) {
    return false;
  }
  // velocidad
  if (lhs->velocidad != rhs->velocidad) {
    return false;
  }
  return true;
}

bool
proy_nexa_interface__msg__Distvel__copy(
  const proy_nexa_interface__msg__Distvel * input,
  proy_nexa_interface__msg__Distvel * output)
{
  if (!input || !output) {
    return false;
  }
  // distancia
  output->distancia = input->distancia;
  // velocidad
  output->velocidad = input->velocidad;
  return true;
}

proy_nexa_interface__msg__Distvel *
proy_nexa_interface__msg__Distvel__create()
{
  proy_nexa_interface__msg__Distvel * msg = (proy_nexa_interface__msg__Distvel *)malloc(sizeof(proy_nexa_interface__msg__Distvel));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(proy_nexa_interface__msg__Distvel));
  bool success = proy_nexa_interface__msg__Distvel__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
proy_nexa_interface__msg__Distvel__destroy(proy_nexa_interface__msg__Distvel * msg)
{
  if (msg) {
    proy_nexa_interface__msg__Distvel__fini(msg);
  }
  free(msg);
}


bool
proy_nexa_interface__msg__Distvel__Sequence__init(proy_nexa_interface__msg__Distvel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  proy_nexa_interface__msg__Distvel * data = NULL;
  if (size) {
    data = (proy_nexa_interface__msg__Distvel *)calloc(size, sizeof(proy_nexa_interface__msg__Distvel));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = proy_nexa_interface__msg__Distvel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        proy_nexa_interface__msg__Distvel__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
proy_nexa_interface__msg__Distvel__Sequence__fini(proy_nexa_interface__msg__Distvel__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      proy_nexa_interface__msg__Distvel__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

proy_nexa_interface__msg__Distvel__Sequence *
proy_nexa_interface__msg__Distvel__Sequence__create(size_t size)
{
  proy_nexa_interface__msg__Distvel__Sequence * array = (proy_nexa_interface__msg__Distvel__Sequence *)malloc(sizeof(proy_nexa_interface__msg__Distvel__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = proy_nexa_interface__msg__Distvel__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
proy_nexa_interface__msg__Distvel__Sequence__destroy(proy_nexa_interface__msg__Distvel__Sequence * array)
{
  if (array) {
    proy_nexa_interface__msg__Distvel__Sequence__fini(array);
  }
  free(array);
}

bool
proy_nexa_interface__msg__Distvel__Sequence__are_equal(const proy_nexa_interface__msg__Distvel__Sequence * lhs, const proy_nexa_interface__msg__Distvel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!proy_nexa_interface__msg__Distvel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
proy_nexa_interface__msg__Distvel__Sequence__copy(
  const proy_nexa_interface__msg__Distvel__Sequence * input,
  proy_nexa_interface__msg__Distvel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(proy_nexa_interface__msg__Distvel);
    proy_nexa_interface__msg__Distvel * data =
      (proy_nexa_interface__msg__Distvel *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!proy_nexa_interface__msg__Distvel__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          proy_nexa_interface__msg__Distvel__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!proy_nexa_interface__msg__Distvel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
