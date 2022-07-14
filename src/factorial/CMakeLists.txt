# WARNING: Wrong file paths with CMake 3.12 or earlier
#TODO: collapse into a list and loop over with for.
add_library(factorial_lib factorial.cc factorial.h)
target_sources(${PROJ_NAME}_${EXE_NAME}
    PRIVATE
    factorial.cc
    factorial.h
    )
