#ifndef MDBTOOLSCPP_MDBSCHEMA_H
#define MDBTOOLSCPP_MDBSCHEMA_H

#include <cstdint>
#include <map>
#include "mdbenums.h"

typedef std::map<char *, char *> HashTable;
typedef void **PtrArray;

namespace mdbtools {
    namespace schema {
        const int PGSIZE = 4096;
        const int MAX_OBJ_NAME = 256;
        const int MAX_COLS = 256;
        const int MAX_IDX_COLS = 10;
        const int CATALOG_PG = 18;
        const int MEMO_OVERHEAD = 12;
        const int BIND_SIZE = 16384;

        struct MdbTypeConstraints {
            MdbTypeConstraints(bool needs_length, bool needs_scale, bool needs_quotes) :
                    needs_length(needs_length),
                    needs_scale(needs_scale),
                    needs_quotes(needs_quotes) {}

            bool needs_length; /* or precision */
            bool needs_scale;
            bool needs_quotes;
        };

        struct MdbBackend {
            MdbSchemaOption capabilities; /* see MDB_SHEXP_* */
            char *types_table;
            char *type_shortdate;
            char *type_autonum;
            const char *short_now;
            const char *long_now;
            const char *charset_statement;
            const char *drop_statement;
            const char *constaint_not_empty_statement;
            const char *column_comment_statement;
            const char *table_comment_statement;

            char *(*quote_schema_name)(const char *, const char *);
        };

        struct MdbStatistics {
            bool collect;
            unsigned long pg_reads;
        };

        struct MdbFile {
            int fd;
            bool writable;
            char *filename;
            uint32_t jet_version;
            uint32_t db_key;
            char db_passwd[14];
            MdbBackend *default_backend;
            char *backend_name;
            MdbStatistics *stats;
            /* free map */
            int map_sz;
            unsigned char *free_map;
            /* reference count */
            int refs;
        };

        /* offset to row count on data pages...version dependant */
        struct MdbFormatConstants {
            ssize_t pg_size;
            uint16_t row_count_offset;
            uint16_t tab_num_rows_offset;
            uint16_t tab_num_cols_offset;
            uint16_t tab_num_idxs_offset;
            uint16_t tab_num_ridxs_offset;
            uint16_t tab_usage_map_offset;
            uint16_t tab_first_dpg_offset;
            uint16_t tab_cols_start_offset;
            uint16_t tab_ridx_entry_size;
            uint16_t col_flags_offset;
            uint16_t col_size_offset;
            uint16_t col_num_offset;
            uint16_t tab_col_entry_size;
            uint16_t tab_free_map_offset;
            uint16_t tab_col_offset_var;
            uint16_t tab_col_offset_fixed;
            uint16_t tab_row_col_num_offset;
        };

        struct MdbHandle {
            MdbFile *file;
            uint32_t cur_pg;
            uint16_t row_num;
            unsigned int cur_pos;
            unsigned char pg_buf[PGSIZE];
            unsigned char alt_pg_buf[PGSIZE];
            unsigned int num_catalog;
            void **catalog; // TODO: FIND TYPE
            MdbBackend *default_backend;
            char *backend_name;
            MdbFormatConstants *format_constants;
            MdbStatistics *statistics;
#ifdef HAVE_ICONV
            iconv_t	iconv_in;
    iconv_t	iconv_out;
#endif
        };


    }
}

#endif //MDBTOOLSCPP_MDBSCHEMA_H
