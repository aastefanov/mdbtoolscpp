#include <iostream>
#include <MdbFile.h>
#include <cstdint>
#include <zconf.h>

void printVersion(mdbtools::MdbFile* file, const std::string &filename) {
    file->open(filename);
    std::cout << (uint16_t) file->getVersion() << std::endl;
}

int main() {
    auto file = new mdbtools::MdbFile();
    printVersion(file, "../testdata/testdb_acc2000.mdb");
    printVersion(file, "../testdata/testdb_acc2003.mdb");
    printVersion(file, "../testdata/testdb_acc2010.accdb");

    return EXIT_SUCCESS;
}