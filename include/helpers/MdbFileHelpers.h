//
// Created by Albert Stefanov on 2019-01-20.
//

#ifndef MDBTOOLSCPP_MDBFILEHELPERS_H
#define MDBTOOLSCPP_MDBFILEHELPERS_H

#include <schema/mdbenums.h>
#include <fstream>


namespace mdbtools {
    namespace helpers {
        class MdbFileHelpers {
        public:
            static mdbtools::schema::MdbFileVersion getVersion(std::ifstream &fs);
        };
    }
}

#endif //MDBTOOLSCPP_MDBFILEHELPERS_H
