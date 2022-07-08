#================
# Define targets
#================

set(EXE_NAME_TEST my_app_test)
add_executable(${PROJ_NAME}_${EXE_NAME_TEST} test.cc)
add_executable(${PROJ_NAME}::${EXE_NAME_TEST} ALIAS ${PROJ_NAME}_${EXE_NAME_TEST})

set_target_properties(${PROJ_NAME}_${EXE_NAME_TEST} PROPERTIES
    OUTPUT_NAME ${EXE_NAME_TEST}
    EXPORT_NAME ${EXE_NAME_TEST}
    )
target_link_libraries(${PROJ_NAME}_${EXE_NAME_TEST} PRIVATE Catch2::Catch2WithMain)
