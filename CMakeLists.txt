cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(root ${PROJECT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${root}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${root}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${root}/output)


include(scripts/cmake/raylib.cmake)
include(scripts/cmake/raygui.cmake)
include(scripts/cmake/rxcpp.cmake)

if(WIN32)
    add_definitions(-DGAME_PLATFORM_WINDOWS)
elseif(APPLE)
    add_definitions(-DGAME_PLATFORM_MACOS)
elseif(UNIX AND NOT APPLE)
    add_definitions(-DGAME_PLATFORM_LINUX)
endif()

include(src/source.cmake)
if(WIN32 AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(game WIN32 ${sources})
else()
    add_executable(game ${sources})
endif()
target_include_directories(game
    PUBLIC ${root}/src
    PUBLIC ${raylib_include}
    PUBLIC ${raygui_include}
    PUBLIC ${rxcpp_include}
)
target_link_libraries(game
    PUBLIC raylib
)
