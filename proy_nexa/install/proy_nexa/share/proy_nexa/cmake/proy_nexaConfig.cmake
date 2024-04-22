# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_proy_nexa_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED proy_nexa_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(proy_nexa_FOUND FALSE)
  elseif(NOT proy_nexa_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(proy_nexa_FOUND FALSE)
  endif()
  return()
endif()
set(_proy_nexa_CONFIG_INCLUDED TRUE)

# output package information
if(NOT proy_nexa_FIND_QUIETLY)
  message(STATUS "Found proy_nexa: 2.1.4 (${proy_nexa_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'proy_nexa' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${proy_nexa_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(proy_nexa_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${proy_nexa_DIR}/${_extra}")
endforeach()
