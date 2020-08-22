set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(raylib_root ${root}/deps/raylib)
set(raylib_include ${raylib_root}/src)

add_subdirectory(${raylib_root})
