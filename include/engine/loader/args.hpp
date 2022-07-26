
//             Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <string>
#include <map>
#include <exception>
#include <vector>

namespace skye2d::loader {

    struct ArgsException : public std::exception {
        const char* what() const throw();
    };

    struct Args {
        std::string gamename;
        std::map<std::string, unsigned short> switches;
        std::map<std::string, std::string> flags;
    };

    Args parseArgs(std::vector<std::string> args);

}