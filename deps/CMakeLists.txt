Include(FetchContent)

# Fetch Catch2 dep.
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.1 # or a later release
    )

# Fetch spdlog dep.
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.x
    )

# Fetch fmt dep.
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        9.0.0
    )

# Add deps.
add_subdirectory(catch)
add_subdirectory(spdlog)
add_subdirectory(fmt)
