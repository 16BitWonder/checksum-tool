#include "md5.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // create a md5 hashing object
    MD5 md5;

    // Quick Test
    std::cout << md5("Quick Test") << std::endl;
    // => B2CCCA5890B65008FC7D7E5B18F645C2

    return 0;
}
