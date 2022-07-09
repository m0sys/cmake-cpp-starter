#================
# Define targets
#================

#### ---- Test as standalone project the exported config package ----
###cmake_minimum_required(VERSION 3.17)
###
###
###project(CmakeConfigPackageTests LANGUAGES CXX)
###set(PROJ_NAME cmake_cpp_starter)
##### if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
###enable_testing()
###find_package(${PROJ_NAME} CONFIG REQUIRED) # for intro, project_options, ...
###if(NOT TARGET ${PROJ_NAME})
###    message(FATAL_ERROR "Requiered config package not found!")
###    return() # be strictly paranoid for Template Janitor github action! CK
###endif()
#####endif()
###
#### ---- Dependencies ----
###add_library(catch_main OBJECT catch_main.cpp)
###target_link_libraries(catch_main PUBLIC Catch2::Catch2)
###target_link_libraries(catch_main PRIVATE ${PROJ_NAME})
###add_executable(tests tests.cpp)
###target_link_libraries(tests PRIVATE ${PROJ_NAME} catch_main)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(EXE_NAME_TEST my_app_test)
add_executable(${PROJ_NAME}_${EXE_NAME_TEST} test.cc )
add_executable(${PROJ_NAME}::${EXE_NAME_TEST} ALIAS ${PROJ_NAME}_${EXE_NAME_TEST})

set_target_properties(${PROJ_NAME}_${EXE_NAME_TEST} PROPERTIES
    OUTPUT_NAME ${EXE_NAME_TEST}
    EXPORT_NAME ${EXE_NAME_TEST}
    )
## target_link_libraries(mylib_test PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${PROJ_NAME}_${EXE_NAME_TEST} PRIVATE Catch2::Catch2WithMain fact_lib)


### automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
### to whatever you want, or use different for different binaries
##catch_discover_tests(
##  tests
##  TEST_PREFIX
##  "unittests."
##  REPORTER
##  xml
##  OUTPUT_DIR
##  .
##  OUTPUT_PREFIX
##  "unittests."
##  OUTPUT_SUFFIX
##  .xml)
