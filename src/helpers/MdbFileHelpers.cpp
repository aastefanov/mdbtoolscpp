//
// Created by Albert Stefanov on 2019-01-20.
//

#include <schema/mdbenums.h>
#include <fstream>
#include <func/endian.h>
#include <helpers/MdbFileHelpers.h>

namespace mdbtools {
    namespace helpers {
        mdbtools::schema::MdbFileVersion mdbtools::helpers::MdbFileHelpers::getVersion(std::ifstream &fs) {
            const std::streampos pos = 0x14;
            const std::streamsize buffsize = 2;

            fs.seekg(pos, fs.beg);
            char *buffer = new char[buffsize];
            fs.read(buffer, buffsize);
            auto res = static_cast<schema::MdbFileVersion>(le16toh(*((uint16_t *) buffer)));
            delete[] buffer;
            return res;
        }
    };
}
