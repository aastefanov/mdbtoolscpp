//
// Created by tr_astefanov on 18.01.2019.
//

#ifndef MDBTOOLSCPP_PAGES_H
#define MDBTOOLSCPP_PAGES_H

#include <cstdint>

namespace mdbtools {
    namespace schema {
        enum class MdbPageType {
            DB = 0,
            DATA,
            TABLE,
            INDEX,
            LEAF,
            MAP
        };

        enum class MdbFileVersion : uint16_t {
            JET3 = 0x00,
            JET4 = 0x01,
            ACCDB_2007 = 0x02,
            ACCDB_2010 = 0x03
        };


        enum class MdbObject {
            FORM = 0,
            TABLE,
            MACRO,
            SYSTEM_TABLE,
            REPORT,
            QUERY,
            LINKED_TABLE,
            MODULE,
            RELATIONSHIP,
            UNKNOWN_09,
            UNKNOWN_0A, /* User access */
            DATABASE_PROPERTY,
            ANY = -1
        };

        enum class MdbType {
            BOOL = 0x01,
            BYTE = 0x02,
            INT = 0x03,
            LONGINT = 0x04,
            MONEY = 0x05,
            FLOAT = 0x06,
            DOUBLE = 0x07,
            DATETIME = 0x08,
            BINARY = 0x09,
            TEXT = 0x0a,
            OLE = 0x0b,
            MEMO = 0x0c,
            REPID = 0x0f,
            NUMERIC = 0x10,
            COMPLEX = 0x12
        };

        enum class MdbOperation {
            OR = 1,
            AND,
            NOT,
            EQUAL,
            GT,
            LT,
            GTEQ,
            LTEQ,
            LIKE,
            ISNULL,
            NOTNULL
        };

        enum class MdbStrategy {
            TABLE_SCAN,
            LEAF_SCAN,
            INDEX_SCAN
        };

        enum class MdbFileFlags {
            NOFLAGS = 0x00,
            WRITABLE = 0x01
        };

        enum class MdbMemo {
            DEBUG_LIKE = 0x0001,
            DEBUG_WRITE = 0x0002,
            DEBUG_USAGE = 0x0004,
            DEBUG_OLE = 0x0008,
            DEBUG_ROW = 0x0010,
            DEBUG_PROPS = 0x0020,
            USE_INDEX = 0x0040,
            NO_MEMO = 0x0080, /* don't follow memo fields */
        };

        enum class MdbSortingStrategy {
            ASC,
            DESC
        };

        enum class MdbIndexStrategy {
            UNIQUE = 0x01,
            IGNORENULLS = 0x02,
            REQUIRED = 0x08
        };

        enum class MdbSchemaExportOptions {
            DROPTABLE = 1 << 0, /* issue drop table during export */
            CST_NOTNULL = 1 << 1, /* generate NOT NULL constraints */
            CST_NOTEMPTY = 1 << 2, /* <>'' constraints */
            COMMENTS = 1 << 3, /* export comments on columns & tables */
            DEFVALUES = 1 << 4, /* export default values */
            INDEXES = 1 << 5, /* export indices */
            RELATIONS = 1 << 6, /* export relation (foreign keys) */
            DEFAULT = CST_NOTNULL | COMMENTS | INDEXES | RELATIONS
        };

        enum class MdbBinaryExportStrategy {
            STRIP,
            RAW,
            OCTAL
        };
    }
}
#endif //MDBTOOLSCPP_PAGES_H
