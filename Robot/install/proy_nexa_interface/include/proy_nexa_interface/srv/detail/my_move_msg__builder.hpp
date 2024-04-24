// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proy_nexa_interface:srv/MyMoveMsg.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__SRV__DETAIL__MY_MOVE_MSG__BUILDER_HPP_
#define PROY_NEXA_INTERFACE__SRV__DETAIL__MY_MOVE_MSG__BUILDER_HPP_

#include "proy_nexa_interface/srv/detail/my_move_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace proy_nexa_interface
{

namespace srv
{

namespace builder
{

class Init_MyMoveMsg_Request_move
{
public:
  Init_MyMoveMsg_Request_move()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::srv::MyMoveMsg_Request move(::proy_nexa_interface::srv::MyMoveMsg_Request::_move_type arg)
  {
    msg_.move = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::srv::MyMoveMsg_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::srv::MyMoveMsg_Request>()
{
  return proy_nexa_interface::srv::builder::Init_MyMoveMsg_Request_move();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace srv
{

namespace builder
{

class Init_MyMoveMsg_Response_success
{
public:
  Init_MyMoveMsg_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::srv::MyMoveMsg_Response success(::proy_nexa_interface::srv::MyMoveMsg_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::srv::MyMoveMsg_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::srv::MyMoveMsg_Response>()
{
  return proy_nexa_interface::srv::builder::Init_MyMoveMsg_Response_success();
}

}  // namespace proy_nexa_interface

#endif  // PROY_NEXA_INTERFACE__SRV__DETAIL__MY_MOVE_MSG__BUILDER_HPP_
