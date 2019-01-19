//
// Created by tr_astefanov on 18.01.2019.
//

#ifndef MDBTOOLSCPP_BACKENDS_H
#define MDBTOOLSCPP_BACKENDS_H

#include <map>

namespace mdbtools {
    enum class MdbBackend {
        Access,
        Sybase,
        Oracle,
        Postgres,
        Mysql,
        Sqlite
    };

    std::map<MdbBackend,>();
}

#endif //MDBTOOLSCPP_BACKENDS_H
