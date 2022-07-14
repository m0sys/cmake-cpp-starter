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

# Add submodules for project.
option(${PROJ_NAME}_COFFEE "Enabling coffee lib" ON)
option(${PROJ_NAME}_LOG "Enabling log lib" ON)
option(${PROJ_NAME}_FACT "Enabling factorial lib" ON)
if (${PROJ_NAME}_COFFEE)
    add_subdirectory(coffee)
endif()
if (${PROJ_NAME}_LOG)
    add_subdirectory(log)
endif()
if (${PROJ_NAME}_FACT)
    add_subdirectory(factorial)
endif()

# Link src deps.
target_link_libraries(${PROJ_NAME}_${EXE_NAME} PRIVATE
    fmt::fmt-header-only
    spdlog::spdlog
    )

