
//                 Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "loader/args.hpp"
#include "loader/draw.hpp"
#include "loader/event.hpp"

using namespace skye2d::loader;

int main(int argc, char** argv) {
    std::vector<std::string> vec_args(argv, argv + argc);
    Args arguments = parseArgs(vec_args);

    int width = std::stoi(arguments.flags["width"]);
    int height = std::stoi(arguments.flags["height"]);
    
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_bool isGameRunning = SDL_TRUE;

    SDL_Init(SDL_INIT_VIDEO);
    win = SDL_CreateWindow(
        "Skye2D Game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        0
    );
    if (win == nullptr) {
        std::cout << "Couldn't create window: " << SDL_GetError() << std::endl;
        return 1;
    }
    renderer = SDL_CreateRenderer(win, -1, 0);

    while (isGameRunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (handleEvent(e)) {
                isGameRunning = SDL_FALSE;
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}