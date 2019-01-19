//
// Created by tr_astefanov on 18.01.2019.
//

#ifndef MDBTOOLSCPP_BUFFERS_H
#define MDBTOOLSCPP_BUFFERS_H

#include <cstdint>
#include <cstring>
#include <istream>

namespace mdbtools {
    namespace func {
        int16_t get_int16(std::istream s, int offset) {
            char* res;
            s.read(res, 2);
            return (int16_t) res;
        }
    }
}

#endif //MDBTOOLSCPP_BUFFERS_H
