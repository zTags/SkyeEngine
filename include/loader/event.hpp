
//             Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <SDL2/SDL.h>

/// Returns if the window should close or not
namespace skye2d::loader {
    bool handleEvent(SDL_Event e);
}