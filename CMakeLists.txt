# config

cmake_minimum_required(VERSION 3.11)
project(Skye2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
set(OpenGL_GL_PREFERENCE GLVND)

include_directories(include)

add_subdirectory(external)

# firstparty

add_subdirectory(engine)
add_subdirectory(editor)