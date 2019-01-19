#include <iostream>
#include "func/endian.h"

#include <stdint.h>


int main() {
    std::cout <<
        be16toh(32) <<
        " " <<
        be32toh(32) <<
        std::endl;
}