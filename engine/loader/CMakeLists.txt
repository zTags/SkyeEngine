add_executable(skye2d 
    main.cpp
    args.cpp
    draw.cpp
    event.cpp
)
target_link_libraries(skye2d PRIVATE SDL2main)
target_link_libraries(skye2d PRIVATE SDL2)