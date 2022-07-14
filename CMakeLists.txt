#==========
# Preamble
#==========
cmake_minimum_required(VERSION 3.17) # v3.17 enables ninja multi-config gen

# TODO: add versioning
set(PROJ_NAME cmake_cpp_starter)
project(${PROJ_NAME}
    VERSION 0.0.1
    LANGUAGES CXX
    )
enable_testing()

#====================
# Project Wide Setup
#====================
list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/cmake # contains useful cmake utils
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# TODO: MAKE build type more robust/clean
# Build type config.
set(MY_BUILD_DIR ${CMAKE_SOURCE_DIR}/build/build_debug)
get_property(BUILDING_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(BUILDING_MULTI_CONFIG)
  if(NOT CMAKE_BUILD_TYPE)
    # Make sure that all supported configuration types have their
    # associated conan packages available. You can reduce this
    # list to only the configuration types you use, but only if one
    # is not forced-set on the command line for VS
    message(TRACE "Setting up multi-config build types")
    set(CMAKE_CONFIGURATION_TYPES
        Debug
        Release
        RelWithDebInfo
        MinSizeRel
        CACHE STRING "Enabled build types" FORCE)
  else()
    message(TRACE "User chose a specific build type, so we are using that")
    set(CMAKE_CONFIGURATION_TYPES
        ${CMAKE_BUILD_TYPE}
        CACHE STRING "Enabled build types" FORCE)
  endif()
endif()

#=============================
# Externally Provided Content
#=============================
add_subdirectory(deps)

#====================
# Main Build Targets
#====================
add_subdirectory(src)

#=======================================================
# Typically needed only if we are the top level project
#=======================================================
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(tests)
endif()
