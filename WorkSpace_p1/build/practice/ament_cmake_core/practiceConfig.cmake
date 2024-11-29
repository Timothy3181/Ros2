# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_practice_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED practice_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(practice_FOUND FALSE)
  elseif(NOT practice_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(practice_FOUND FALSE)
  endif()
  return()
endif()
set(_practice_CONFIG_INCLUDED TRUE)

# output package information
if(NOT practice_FIND_QUIETLY)
  message(STATUS "Found practice: 0.0.0 (${practice_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'practice' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${practice_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(practice_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${practice_DIR}/${_extra}")
endforeach()
