cmake_minimum_required(VERSION 3.17) # v3.17 enables ninja multi-config gen
project(cmake_cpp_starter LANGUAGES CXX)

# Define build types i.e. Debug|Release.
add_executable(my_app main.cc)
add_executable(my_app_debug main.cc)

# Build type config.
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

##get_property(isMultiConfig GLOBAL
##    PROPERTY GENERATOR_IS_MULTI_CONFIG
##)
##if(isMultiConfig)
##    if(NOT "Profile" IN_LIST CMAKE_CONFIGURATION_TYPES)
##        list(APPEND CMAKE_CONFIGURATION_TYPES Profile)
##    endif()
##else()
##    set(allowedBuildTypes Debug Release Profile)
##    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
##        STRINGS "${allowedBuildTypes}"
##    )
##    if(NOT CMAKE_BUILD_TYPE)
##        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
##    elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
##        message(FATAL_ERROR
##            "Unknown build type: ${CMAKE_BUILD_TYPE}"
##        )
##    endif()
##endif()
