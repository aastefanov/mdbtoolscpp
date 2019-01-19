#ifndef MDBTOOLSCPP_MDBTABLE_H
#define MDBTOOLSCPP_MDBTABLE_H

#include "mdbschema.h"

namespace mdbtools {
    namespace schema {
        struct MdbProperty {
            char *name;
            HashTable *hash;
        };

        struct MdbColumn {
            struct S_MdbTableDef *table;
            char name[MAX_OBJ_NAME + 1];
            int col_type;
            int col_size;
            void *bind_ptr;
            int *len_ptr;
            HashTable *properties;
            unsigned int num_sargs;
            PtrArray *sargs;
            PtrArray *idx_sarg_cache;
            unsigned char is_fixed;
            int query_order;
            /* col_num is the current column order,
             * does not include deletes */
            int col_num;
            int cur_value_start;
            int cur_value_len;
            /* MEMO/OLE readers */
            uint32_t cur_blob_pg_row;
            int chunk_size;
            /* numerics only */
            int col_prec;
            int col_scale;
            unsigned char is_long_auto;
            unsigned char is_uuid_auto;
            MdbProperty **props;
            /* info needed for handling deleted/added columns */
            int fixed_offset;
            unsigned int var_col_num;
            /* row_col_num is the row column number order,
             * including deleted columns */
            int row_col_num;
        };


        struct MdbCatalogEntry {
            MdbHandle *mdb;
            char object_name[MAX_OBJ_NAME + 1];
            int object_type;
            unsigned long table_pg; /* misnomer since object may not be a table */
            //int			num_props; please use props->len
            MdbProperty **props; /* GArray of MdbProperties */
            MdbColumn *columns[MAX_COLS];
            int flags;
        };

        struct MdbIndexPage {
            uint32_t pg;
            int start_pos;
            int offset;
            int len;
            uint16_t idx_starts[2000];
            unsigned char cache_value[256];
        };

        union MdbAny {
            int	i;
            double	d;
            char	s[256];
        };
    }
}
#endif //MDBTOOLSCPP_MDBTABLE_H
