add_executable(skye2d_editor_browser
    main.cpp
    draw.cpp
    state.cpp
    styles.cpp
    "internal/imgui_impl_sdl.cpp"
    "internal/imgui_impl_opengl3.cpp"
)

target_link_libraries(skye2d_editor_browser SDL2main SDL2 ImGUI ${CMAKE_DL_LIBS})

if (WIN32)
    target_link_libraries(skye2d_editor_browser OpenGL32)
endif (WIN32)

if (UNIX)
    target_link_libraries(skye2d_editor_browser OpenGL)
endif (UNIX)