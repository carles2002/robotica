#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "async_web_server_cpp::async_web_server_cpp" for configuration ""
set_property(TARGET async_web_server_cpp::async_web_server_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(async_web_server_cpp::async_web_server_cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libasync_web_server_cpp.so.2.0.0"
  IMPORTED_SONAME_NOCONFIG "libasync_web_server_cpp.so.1"
  )

list(APPEND _cmake_import_check_targets async_web_server_cpp::async_web_server_cpp )
list(APPEND _cmake_import_check_files_for_async_web_server_cpp::async_web_server_cpp "${_IMPORT_PREFIX}/lib/libasync_web_server_cpp.so.2.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
