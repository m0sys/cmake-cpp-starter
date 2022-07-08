#==========
# Preamble
#==========
cmake_minimum_required(VERSION 3.17) # v3.17 enables ninja multi-config gen

# TODO: add versioning
set(PROJ_NAME cmake_cpp_starter)
project(${PROJ_NAME} LANGUAGES CXX)
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

#=============================
# Externally Provided Content
#=============================
add_subdirectory(deps)

######################
# Main Build Targets #
######################
add_subdirectory(src)

#=======================================================
# Typically needed only if we are the top level project
#=======================================================
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(tests)
endif()
