// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from proy_nexa_interface:action/Move.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__BUILDER_HPP_
#define PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__BUILDER_HPP_

#include "proy_nexa_interface/action/detail/move__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_Goal_secs
{
public:
  Init_Move_Goal_secs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::action::Move_Goal secs(::proy_nexa_interface::action::Move_Goal::_secs_type arg)
  {
    msg_.secs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_Goal>()
{
  return proy_nexa_interface::action::builder::Init_Move_Goal_secs();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_Result_status
{
public:
  Init_Move_Result_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::action::Move_Result status(::proy_nexa_interface::action::Move_Result::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_Result>()
{
  return proy_nexa_interface::action::builder::Init_Move_Result_status();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_Feedback_feedback
{
public:
  Init_Move_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::action::Move_Feedback feedback(::proy_nexa_interface::action::Move_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_Feedback>()
{
  return proy_nexa_interface::action::builder::Init_Move_Feedback_feedback();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Request_goal
{
public:
  explicit Init_Move_SendGoal_Request_goal(::proy_nexa_interface::action::Move_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::proy_nexa_interface::action::Move_SendGoal_Request goal(::proy_nexa_interface::action::Move_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_SendGoal_Request msg_;
};

class Init_Move_SendGoal_Request_goal_id
{
public:
  Init_Move_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Request_goal goal_id(::proy_nexa_interface::action::Move_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_SendGoal_Request_goal(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_SendGoal_Request>()
{
  return proy_nexa_interface::action::builder::Init_Move_SendGoal_Request_goal_id();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Response_stamp
{
public:
  explicit Init_Move_SendGoal_Response_stamp(::proy_nexa_interface::action::Move_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::proy_nexa_interface::action::Move_SendGoal_Response stamp(::proy_nexa_interface::action::Move_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_SendGoal_Response msg_;
};

class Init_Move_SendGoal_Response_accepted
{
public:
  Init_Move_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Response_stamp accepted(::proy_nexa_interface::action::Move_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Move_SendGoal_Response_stamp(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_SendGoal_Response>()
{
  return proy_nexa_interface::action::builder::Init_Move_SendGoal_Response_accepted();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Request_goal_id
{
public:
  Init_Move_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::proy_nexa_interface::action::Move_GetResult_Request goal_id(::proy_nexa_interface::action::Move_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_GetResult_Request>()
{
  return proy_nexa_interface::action::builder::Init_Move_GetResult_Request_goal_id();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Response_result
{
public:
  explicit Init_Move_GetResult_Response_result(::proy_nexa_interface::action::Move_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::proy_nexa_interface::action::Move_GetResult_Response result(::proy_nexa_interface::action::Move_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_GetResult_Response msg_;
};

class Init_Move_GetResult_Response_status
{
public:
  Init_Move_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_GetResult_Response_result status(::proy_nexa_interface::action::Move_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Move_GetResult_Response_result(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_GetResult_Response>()
{
  return proy_nexa_interface::action::builder::Init_Move_GetResult_Response_status();
}

}  // namespace proy_nexa_interface


namespace proy_nexa_interface
{

namespace action
{

namespace builder
{

class Init_Move_FeedbackMessage_feedback
{
public:
  explicit Init_Move_FeedbackMessage_feedback(::proy_nexa_interface::action::Move_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::proy_nexa_interface::action::Move_FeedbackMessage feedback(::proy_nexa_interface::action::Move_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_FeedbackMessage msg_;
};

class Init_Move_FeedbackMessage_goal_id
{
public:
  Init_Move_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_FeedbackMessage_feedback goal_id(::proy_nexa_interface::action::Move_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_FeedbackMessage_feedback(msg_);
  }

private:
  ::proy_nexa_interface::action::Move_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::proy_nexa_interface::action::Move_FeedbackMessage>()
{
  return proy_nexa_interface::action::builder::Init_Move_FeedbackMessage_goal_id();
}

}  // namespace proy_nexa_interface

#endif  // PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__BUILDER_HPP_
