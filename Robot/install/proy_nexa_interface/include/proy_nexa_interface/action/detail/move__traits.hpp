// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from proy_nexa_interface:action/Move.idl
// generated code does not contain a copyright notice

#ifndef PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__TRAITS_HPP_
#define PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__TRAITS_HPP_

#include "proy_nexa_interface/action/detail/move__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: secs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "secs: ";
    value_to_yaml(msg.secs, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_Goal & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_Goal>()
{
  return "proy_nexa_interface::action::Move_Goal";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_Goal>()
{
  return "proy_nexa_interface/action/Move_Goal";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<proy_nexa_interface::action::Move_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_Result & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_Result>()
{
  return "proy_nexa_interface::action::Move_Result";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_Result>()
{
  return "proy_nexa_interface/action/Move_Result";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<proy_nexa_interface::action::Move_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback: ";
    value_to_yaml(msg.feedback, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_Feedback & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_Feedback>()
{
  return "proy_nexa_interface::action::Move_Feedback";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_Feedback>()
{
  return "proy_nexa_interface/action/Move_Feedback";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<proy_nexa_interface::action::Move_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "proy_nexa_interface/action/detail/move__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_SendGoal_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_SendGoal_Request>()
{
  return "proy_nexa_interface::action::Move_SendGoal_Request";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_SendGoal_Request>()
{
  return "proy_nexa_interface/action/Move_SendGoal_Request";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<proy_nexa_interface::action::Move_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<proy_nexa_interface::action::Move_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<proy_nexa_interface::action::Move_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_SendGoal_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_SendGoal_Response>()
{
  return "proy_nexa_interface::action::Move_SendGoal_Response";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_SendGoal_Response>()
{
  return "proy_nexa_interface/action/Move_SendGoal_Response";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<proy_nexa_interface::action::Move_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<proy_nexa_interface::action::Move_SendGoal>()
{
  return "proy_nexa_interface::action::Move_SendGoal";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_SendGoal>()
{
  return "proy_nexa_interface/action/Move_SendGoal";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<proy_nexa_interface::action::Move_SendGoal_Request>::value &&
    has_fixed_size<proy_nexa_interface::action::Move_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<proy_nexa_interface::action::Move_SendGoal_Request>::value &&
    has_bounded_size<proy_nexa_interface::action::Move_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<proy_nexa_interface::action::Move_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<proy_nexa_interface::action::Move_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<proy_nexa_interface::action::Move_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_GetResult_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_GetResult_Request>()
{
  return "proy_nexa_interface::action::Move_GetResult_Request";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_GetResult_Request>()
{
  return "proy_nexa_interface/action/Move_GetResult_Request";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<proy_nexa_interface::action::Move_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "proy_nexa_interface/action/detail/move__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_GetResult_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_GetResult_Response>()
{
  return "proy_nexa_interface::action::Move_GetResult_Response";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_GetResult_Response>()
{
  return "proy_nexa_interface/action/Move_GetResult_Response";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<proy_nexa_interface::action::Move_Result>::value> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<proy_nexa_interface::action::Move_Result>::value> {};

template<>
struct is_message<proy_nexa_interface::action::Move_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<proy_nexa_interface::action::Move_GetResult>()
{
  return "proy_nexa_interface::action::Move_GetResult";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_GetResult>()
{
  return "proy_nexa_interface/action/Move_GetResult";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<proy_nexa_interface::action::Move_GetResult_Request>::value &&
    has_fixed_size<proy_nexa_interface::action::Move_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<proy_nexa_interface::action::Move_GetResult_Request>::value &&
    has_bounded_size<proy_nexa_interface::action::Move_GetResult_Response>::value
  >
{
};

template<>
struct is_service<proy_nexa_interface::action::Move_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<proy_nexa_interface::action::Move_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<proy_nexa_interface::action::Move_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "proy_nexa_interface/action/detail/move__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const proy_nexa_interface::action::Move_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const proy_nexa_interface::action::Move_FeedbackMessage & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<proy_nexa_interface::action::Move_FeedbackMessage>()
{
  return "proy_nexa_interface::action::Move_FeedbackMessage";
}

template<>
inline const char * name<proy_nexa_interface::action::Move_FeedbackMessage>()
{
  return "proy_nexa_interface/action/Move_FeedbackMessage";
}

template<>
struct has_fixed_size<proy_nexa_interface::action::Move_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<proy_nexa_interface::action::Move_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<proy_nexa_interface::action::Move_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<proy_nexa_interface::action::Move_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<proy_nexa_interface::action::Move_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<proy_nexa_interface::action::Move>
  : std::true_type
{
};

template<>
struct is_action_goal<proy_nexa_interface::action::Move_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<proy_nexa_interface::action::Move_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<proy_nexa_interface::action::Move_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // PROY_NEXA_INTERFACE__ACTION__DETAIL__MOVE__TRAITS_HPP_
