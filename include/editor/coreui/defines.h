
//             Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifdef __linux__

#define DATADIR ".local/skye2d"

#elif _WIN32

#define DATADIR "AppData\\Local\\skye2d"

#elif __APPLE__

#define DATADIR "Library/Application Support/skye2d"

#else

#error Unsupported Operating System!

#endif