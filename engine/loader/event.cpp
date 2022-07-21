
//             Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)



#include <SDL2/SDL.h>

namespace skye2d::loader {

    bool handleEvent(SDL_Event e) {
        switch (e.type) {
            case SDL_QUIT:
                return true;
            default:
                return false;
        }
    }

}