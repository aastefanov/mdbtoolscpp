#ifndef MDBTOOLSCPP_FILE_H
#define MDBTOOLSCPP_FILE_H

#include <cstddef>
#include <schema/mdbschema.h>
#include <schema/mdbenums.h>
#include <fstream>

namespace mdbtools {

    class MdbFile {
    private:
        std::ifstream fileStream;
        schema::MdbFileVersion version;
    public:
        void open(const std::string &filename);
        schema::MdbFileVersion getVersion() const;
        ~MdbFile();
    };

    extern size_t mdb_read_pg(mdbtools::schema::MdbHandle *mdb, unsigned long pg);

    extern size_t mdb_read_alt_pg(mdbtools::schema::MdbHandle *mdb, unsigned long pg);

    extern unsigned char mdb_get_byte(void *buf, int offset);

    extern int mdb_get_int16(void *buf, int offset);

    extern long mdb_get_int32(void *buf, int offset);

    extern long mdb_get_int32_msb(void *buf, int offset);

    extern float mdb_get_single(void *buf, int offset);

    extern double mdb_get_double(void *buf, int offset);

    extern unsigned char mdb_pg_get_byte(mdbtools::schema::MdbHandle *mdb, int offset);

    extern int mdb_pg_get_int16(mdbtools::schema::MdbHandle *mdb, int offset);

    extern long mdb_pg_get_int32(mdbtools::schema::MdbHandle *mdb, int offset);

    extern float mdb_pg_get_single(mdbtools::schema::MdbHandle *mdb, int offset);

    extern double mdb_pg_get_double(mdbtools::schema::MdbHandle *mdb, int offset);

    extern mdbtools::schema::MdbHandle *mdb_open(const char *filename, mdbtools::schema::MdbFileFlags flags);

    extern void mdb_close(mdbtools::schema::MdbHandle *mdb);

    extern mdbtools::schema::MdbHandle *mdb_clone_handle(mdbtools::schema::MdbHandle *mdb);

    extern void mdb_swap_pgbuf(mdbtools::schema::MdbHandle *mdb);
}

#endif //MDBTOOLSCPP_FILE_H
