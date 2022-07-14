#================
# Define targets
#================

include_directories(${CMAKE_SOURCE_DIR}/src)

set(EXE_NAME_TEST my_app_test)
add_executable(${PROJ_NAME}_${EXE_NAME_TEST} test.cc)
add_executable(${PROJ_NAME}::${EXE_NAME_TEST} ALIAS ${PROJ_NAME}_${EXE_NAME_TEST})

set_target_properties(${PROJ_NAME}_${EXE_NAME_TEST} PROPERTIES
    OUTPUT_NAME ${EXE_NAME_TEST}
    EXPORT_NAME ${EXE_NAME_TEST}
    )

# NOTE: if src needs extern deps then you will have to link them to the lib
#       before linking lib to test.
target_link_libraries(factorial_lib PRIVATE
    spdlog::spdlog
    )
target_link_libraries(${PROJ_NAME}_${EXE_NAME_TEST} PRIVATE Catch2::Catch2WithMain factorial_lib)

# TODO: integrate catch_discover_tests.
### automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
### to whatever you want, or use different for different binaries
set(catch2_SOURCE_DIR ${MY_BUILD_DIR}/_deps/catch2-src)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include (CTest)
include (Catch)
catch_discover_tests(
  ${PROJ_NAME}_${EXE_NAME_TEST}
  TEST_PREFIX
  "unittests."
  # NOTE: not supported on apple silicon.
  ## REPORTER
  ## xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "unittests."
  OUTPUT_SUFFIX
  .xml)
