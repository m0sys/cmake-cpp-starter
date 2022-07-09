# WARNING: Wrong file paths with CMake 3.12 or earlier
add_library(fact_lib factorial.cc factorial.h)
target_sources(${PROJ_NAME}_${EXE_NAME}
    PRIVATE
    factorial.cc
    factorial.h
    )
