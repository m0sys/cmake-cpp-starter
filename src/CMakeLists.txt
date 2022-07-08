#================
# Define targets
#================

set(EXE_NAME my_app)
add_executable(${PROJ_NAME}_${EXE_NAME} main.cc)
add_executable(${PROJ_NAME}::${EXE_NAME} ALIAS ${PROJ_NAME}_${EXE_NAME})

set_target_properties(${PROJ_NAME}_${EXE_NAME} PROPERTIES
    OUTPUT_NAME ${EXE_NAME}
    EXPORT_NAME ${EXE_NAME}
    )
