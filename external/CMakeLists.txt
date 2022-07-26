# includes are handled by symlinking in /include

# OpenGL 
find_package(OpenGL REQUIRED)

# sdl2
add_subdirectory(SDL)

# imgui
add_library(ImGUI
    ImGUI/imgui.cpp
    ImGUI/imgui_demo.cpp
    ImGUI/imgui_draw.cpp
    ImGUI/imgui_tables.cpp
    ImGUI/imgui_widgets.cpp
)