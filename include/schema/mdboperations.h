#ifndef MDBTOOLSCPP_MDBOPERATIONS_H
#define MDBTOOLSCPP_MDBOPERATIONS_H

#include "mdbenums.h"

namespace mdbtools {
    namespace schema {
        bool MdbOperation_isLogical(const MdbOperation* op) {
            return *op == MdbOperation::AND || *op == MdbOperation::OR || *op == MdbOperation::NOT;
        }

        bool MdbOperation_isRelational(const MdbOperation* op) {
            return !MdbOperation_isLogical(op);
        }
    }
}

#endif //MDBTOOLSCPP_MDBOPERATIONS_H
