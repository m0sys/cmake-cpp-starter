Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.1 # or a later release
    )

# TODO: fetch spdlog
# TODO: fetch fmt

add_subdirectory(catch)
# TODO: add spdlog
# TODO: add fmt
