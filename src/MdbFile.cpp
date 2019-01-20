#include <schema/mdbschema.h>
#include <schema/mdbenums.h>
#include <fstream>
#include <string>
#include <MdbFile.h>
#include <helpers/MdbFileHelpers.h>

namespace mdbtools {
    void MdbFile::open(const std::string &filename) {
        fileStream = std::ifstream();
        fileStream.exceptions(std::ifstream::failbit);
        fileStream.open(filename, std::ifstream::binary | std::ifstream::in);

        version = mdbtools::helpers::MdbFileHelpers::getVersion(fileStream);

    }

    mdbtools::schema::MdbFileVersion MdbFile::getVersion() const { return version; }

    MdbFile::~MdbFile() {
        fileStream.close();
    }
};
