// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proy_nexa_interface:msg/Distvel.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__BUILDER_HPP_
#define PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__BUILDER_HPP_

#include "proy_nexa_interface/msg/detail/distvel__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace proy_nexa_interface
{

namespace msg
{

namespace builder
{

class Init_Distvel_velocidad
{
public:
  explicit Init_Distvel_velocidad(::proy_nexa_interface::msg::Distvel & msg)
  : msg_(msg)
  {}
  ::proy_nexa_interface::msg::Distvel velocidad(::proy_nexa_interface::msg::Distvel::_velocidad_type arg)
  {
    msg_.velocidad = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::msg::Distvel msg_;
};

class Init_Distvel_distancia
{
public:
  Init_Distvel_distancia()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Distvel_velocidad distancia(::proy_nexa_interface::msg::Distvel::_distancia_type arg)
  {
    msg_.distancia = std::move(arg);
    return Init_Distvel_velocidad(msg_);
  }

private:
  ::proy_nexa_interface::msg::Distvel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::msg::Distvel>()
{
  return proy_nexa_interface::msg::builder::Init_Distvel_distancia();
}

}  // namespace proy_nexa_interface

#endif  // PROY_NEXA_INTERFACE__MSG__DETAIL__DISTVEL__BUILDER_HPP_
