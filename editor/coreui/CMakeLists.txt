add_executable(skye2d_editor 
    main.cpp
    "internal/imgui_impl_sdl.cpp"
    "internal/imgui_impl_opengl3.cpp"
)

target_link_libraries(skye2d_editor SDL2main SDL2 ImGUI ${CMAKE_DL_LIBS} OpenGL)