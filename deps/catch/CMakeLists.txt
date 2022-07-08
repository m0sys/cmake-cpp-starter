set(BUILD_SHARED_LIBS NO)
set_directory_properties(PROPERTIES
    EXCLUDE_FROM_ALL YES
)

FetchContent_MakeAvailable(Catch2)
