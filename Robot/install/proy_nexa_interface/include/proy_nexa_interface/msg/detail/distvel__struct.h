// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from proy_nexa_interface:msg/Distvel.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__STRUCT_H_
#define PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Distvel in the package proy_nexa_interface.
typedef struct proy_nexa_interface__msg__Distvel
{
  int64_t distancia;
  double velocidad;
} proy_nexa_interface__msg__Distvel;

// Struct for a sequence of proy_nexa_interface__msg__Distvel.
typedef struct proy_nexa_interface__msg__Distvel__Sequence
{
  proy_nexa_interface__msg__Distvel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} proy_nexa_interface__msg__Distvel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__STRUCT_H_
