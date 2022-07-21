
//             Copyright tags 2022.
// Distributed under the Boost Software License, Version 1.0.
//         (See accompanying file LICENSE or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <map>
#include <string>
#include <tuple>
#include <exception>
#include <vector>
#include <algorithm>

namespace skye2d::loader {
    struct ArgsException : public std::exception {
        const char* what() const throw() {
            return "Failure to parse arguments";
        }
    };

    struct Args {
        std::string gamename;
        std::map<std::string, unsigned short> switches;
        std::map<std::string, std::string> flags;
    };
    
    Args parseArgs(std::vector<std::string> args) {
        /// how to use: std::make_tuple(name, allowShortFlag)
        /// example:
        /// std::make_tuple("verbose", true);
        /// std::make_tuple("force-opengl", false)
        /// usage:
        /// skye2d --verbose -v
        /// skye2d --force-opengl
        /// NOT: skye2d -f
        std::tuple<std::string, bool> allowedSwitches[1] = {
            std::make_tuple("fullscreen", true)
        };

        std::tuple<std::string, bool> allowedFlags[2] = {
            std::make_tuple("width", true),
            std::make_tuple("height", true)
        };


        if (args.size() == 1) {
            throw ArgsException();
        }

        // for struct construction at the end
        std::string gamename(args[1]);
        std::map<std::string, unsigned short> switches;
        std::map<std::string, std::string> flags;
        Args arguments;

        // parse switches
        for (const auto& _switch : allowedSwitches) {
            // match long form
            std::string switchname = std::get<0>(_switch);
            switchname.insert(0, "--");
            int amount = std::count(args.begin(), args.end(), switchname);
            // match short form
            if (std::get<1>(_switch)) {
                char shortswitchChar = std::get<0>(_switch)[0];
                std::string shortswitch(1, shortswitchChar);
                shortswitch.insert(0, "-");
                amount += std::count(args.begin(), args.end(), shortswitch);
            }
            switches[std::get<0>(_switch)] = amount;
        }

        // parse flags
        long unsigned int i = 0;
        for (const auto& arg : args) {
            if (i == 0) { 
                i++;
                continue;
            }

            for (const auto& flag : allowedFlags) {
                // long form
                std::string fullflag = std::get<0>(flag);
                fullflag.insert(0, "--");
                if (arg == fullflag) {
                    if (i + 1 > args.size()) throw ArgsException();
                    flags[std::get<0>(flag)] = args[i+1];
                }

                // short form
                if (std::get<1>(flag)) {
                    char fullflagChar = std::get<0>(flag)[0];
                    std::string fullflag(1, fullflagChar);
                    fullflag.insert(0, "-");
                    if (arg == fullflag) {
                        if (i + 1 > args.size()) throw ArgsException();
                        flags[std::get<0>(flag)] = args[i+1];
                    }
                }
            }
            i++;
        }

        arguments.gamename = gamename;
        arguments.switches = switches;
        arguments.flags = flags;

        return arguments;
    }
}