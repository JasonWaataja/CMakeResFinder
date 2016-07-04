# CMakeResFinder
A simpe library to find resources dynamically for use with CMake written in C.

# Installation
You will need CMake to install it. Create a directory to build in. `mkdir build && cd build`. Then run `cmake ..`. Then build the
project like you would for any other project and install it. For Unix and Linux, run `make` and `sudo make install`

# Usage
Installing the library wiil install a cmrf.cmake file which you can use in your own programming. Include it in your project and
cmrf.h. Remember to initlalize the library with any number of absolute paths with cmrf_init (). Set the int arg to be the number
of absolute paths you pass. You can then add relative, absolute, and cmake_prefix search paths with their respective search
functions. Call cmrf_find_resource () which returns a cstring with the absolute path to the resource and NULL otherwise. Remember
to free the generated cstring with free () afterwards. Call cmrf_exit () at the end to clean up any other resources.
