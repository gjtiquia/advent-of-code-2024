#!/usr/bin/bash 

echo "Build: Compiling main.cpp into executable 'main'..."

# Increase warning level with these flags before the filename: -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion
# (source: https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/)

# Treat warnings as errors with the following flag before the filename: -Werror
# The compiler will halt compilation if it finds any warnings
# (source: https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/)

g++ \
    src/**.cpp src/**/*.cpp \
    -I src -I src/Day1 -I src/Day2 -I src/Day3 \
    -I lib/fmt/include \
    -o main \
    # Commented bcs fmt library throws a lot of errors (which are treated as errors here😂)
    # -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion \
    # -Werror

lastExitCode=$?
if [ $lastExitCode != 0 ]; then
    echo "Build: Failed! Exit Code: ${lastExitCode}" 
    exit $lastExitCode
fi

echo "Build: Success! Exit Code: ${lastExitCode}"