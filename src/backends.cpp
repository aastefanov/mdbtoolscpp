#include <schema/mdbschema.h>

using namespace mdbtools::schema;

enum class MdbBackendName {
    Access,
    Sybase,
    Oracle,
    Postgres,
    Mysql,
    Sqlite
};


static std::map<MdbBackendName, std::map<const char *, MdbTypeConstraints>> backends{
        {MdbBackendName::Access, std::map<const char *, MdbTypeConstraints>{
                {"Unknown 0x00",   MdbTypeConstraints(false, false, false)},
                {"Boolean",        MdbTypeConstraints(false, false, false)},
                {"Byte",           MdbTypeConstraints(false, false, false)},
                {"Integer",        MdbTypeConstraints(false, false, false)},
                {"Long Integer",   MdbTypeConstraints(false, false, false)},
                {"Currency",       MdbTypeConstraints(false, false, false)},
                {"Single",         MdbTypeConstraints(false, false, false)},
                {"Double",         MdbTypeConstraints(false, false, false)},
                {"DateTime",       MdbTypeConstraints(false, false, true)},
                {"Binary",         MdbTypeConstraints(false, false, false)},
                {"Text",           MdbTypeConstraints(true, false, true)},
                {"OLE",            MdbTypeConstraints(true, false, true)},
                {"Memo/Hyperlink", MdbTypeConstraints(true, false, true)},
                {"Unknown 0x0d",   MdbTypeConstraints(false, false, false)},
                {"Unknown 0x0e",   MdbTypeConstraints(false, false, false)},
                {"Replication ID", MdbTypeConstraints(false, false, false)},
                {"Numeric",        MdbTypeConstraints(true, true, false)}
        }},
        {MdbBackendName::Oracle, std::map<const char *, MdbTypeConstraints>{
                {"Oracle_Unknown 0x00", MdbTypeConstraints(false, false, false)},
                {"NUMBER(true)",        MdbTypeConstraints(false, false, false)},
                {"NUMBER(3)",           MdbTypeConstraints(false, false, false)},
                {"NUMBER(5)",           MdbTypeConstraints(false, false, false)},
                {"NUMBER(1true)",       MdbTypeConstraints(false, false, false)},
                {"NUMBER(15,2)",        MdbTypeConstraints(false, false, false)},
                {"FLOAT",               MdbTypeConstraints(false, false, false)},
                {"FLOAT",               MdbTypeConstraints(false, false, false)},
                {"TIMESTAMP",           MdbTypeConstraints(false, false, false)},
                {"BINARY",              MdbTypeConstraints(false, false, false)},
                {"VARCHAR2",            MdbTypeConstraints(true, false, true)},
                {"BLOB",                MdbTypeConstraints(false, false, false)},
                {"CLOB",                MdbTypeConstraints(false, false, false)},
                {"Oracle_Unknown 0x0d", MdbTypeConstraints(false, false, false)},
                {"Oracle_Unknown 0x0e", MdbTypeConstraints(false, false, false)},
                {"NUMBER",              MdbTypeConstraints(true, false, false)},
                {"NUMBER",              MdbTypeConstraints(true, false, false)}
        }
        }};
//static MdbBackendType mdb_oracle_shortdate_type =
//        {"DATE",MdbTypeConstraints(false, false, false};
//
///*    Sybase/MSSQL data types */
//static MdbBackendType mdb_sybase_types[] = {
//        {"Sybase_Unknown 0x00",MdbTypeConstraints(false, false, false)},
//        {"bit",MdbTypeConstraints(false, false, false)},
//        {"char",MdbTypeConstraints(true, false, true)},
//        {"smallint",MdbTypeConstraints(false, false, false)},
//        {"int",MdbTypeConstraints(false, false, false)},
//        {"money",MdbTypeConstraints(false, false, false)},
//        {"real",MdbTypeConstraints(false, false, false)},
//        {"float",MdbTypeConstraints(false, false, false)},
//        {"smalldatetime",MdbTypeConstraints(false, false, false)},
//        {"Sybase_Unknown 0x09",MdbTypeConstraints(false, false, false)},
//        {"varchar",MdbTypeConstraints(true, false, true)},
//        {"varbinary",MdbTypeConstraints(true, false, true)},
//        {"text",MdbTypeConstraints(true, false, true)},
//        {"Sybase_Unknown 0x0d",MdbTypeConstraints(false, false, false)},
//        {"Sybase_Unknown 0x0e",MdbTypeConstraints(false, false, false)},
//        {"Sybase_Replication ID",MdbTypeConstraints(false, false, false)},
//        {"numeric",MdbTypeConstraints(true, true, false)},
//};
//static MdbBackendType mdb_sybase_shortdate_type =
//        {"DATE",MdbTypeConstraints(false, false, false);
//
///*    Postgres data types */
//static MdbBackendType mdb_postgres_types[] = {
//        {"Postgres_Unknown 0x00",MdbTypeConstraints(false, false, false)},
//        {"BOOL",MdbTypeConstraints(false, false, false)},
//        {"SMALLINT",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false), /* bigint */
//        {"NUMERIC(15,2)",MdbTypeConstraints(false, false, false), /* money deprecated ? */
//        {"REAL",MdbTypeConstraints(false, false, false)},
//        {"DOUBLE PRECISION",MdbTypeConstraints(false, false, false)},
//        {"TIMESTAMP WITHOUT TIME ZONE",MdbTypeConstraints(false, false, false)},
//        {"BYTEA",MdbTypeConstraints(false, false, false)},
//        {"VARCHAR",MdbTypeConstraints(true, false, true)},
//        {"BYTEA",MdbTypeConstraints(false, false, false)},
//        {"TEXT",MdbTypeConstraints(false, false, false)},
//        {"Postgres_Unknown 0x0d",MdbTypeConstraints(false, false, false)},
//        {"Postgres_Unknown 0x0e",MdbTypeConstraints(false, false, false)},
//        {"UUID",MdbTypeConstraints(false, false, false)},
//        {"Postgres_Unknown 0x10",MdbTypeConstraints(false, false, false)},
//};
//static MdbBackendType mdb_postgres_shortdate_type =
//        {"DATE",MdbTypeConstraints(false, false, false);
//static MdbBackendType mdb_postgres_serial_type =
//        {"SERIAL",MdbTypeConstraints(false, false, false);
//
///*    MySQL data types */
//static MdbBackendType mdb_mysql_types[] = {
//        {"Text",MdbTypeConstraints(true, false, true)},
//        {"char",MdbTypeConstraints(false, false, false)},
//        {"int",MdbTypeConstraints(false, false, false)},
//        {"int",MdbTypeConstraints(false, false, false)},
//        {"int",MdbTypeConstraints(false, false, false)},
//        {"float",MdbTypeConstraints(false, false, false)},
//        {"float",MdbTypeConstraints(false, false, false)},
//        {"float",MdbTypeConstraints(false, false, false)},
//        {"datetime",MdbTypeConstraints(false, false, true)},
//        {"varchar",MdbTypeConstraints(true, false, true)},
//        {"varchar",MdbTypeConstraints(true, false, true)},
//        {"varchar",MdbTypeConstraints(true, false, true)},
//        {"text",MdbTypeConstraints(true, false, true)},
//        {"blob",MdbTypeConstraints(false, false, false)},
//        {"text",MdbTypeConstraints(true, false, true)},
//        {"char(38)",MdbTypeConstraints(false, false, false)},
//        {"numeric",MdbTypeConstraints(true, true, false)},
//};
//static MdbBackendType mdb_mysql_shortdate_type =
//        {"date",MdbTypeConstraints(false, false, false);
//
///*    sqlite data types */
//static MdbBackendType mdb_sqlite_types[] = {
//        {"BLOB",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"REAL",MdbTypeConstraints(false, false, false)},
//        {"REAL",MdbTypeConstraints(false, false, false)},
//        {"REAL",MdbTypeConstraints(false, false, false)},
//        {"DateTime",MdbTypeConstraints(false, false, true)},
//        {"BLOB",MdbTypeConstraints(false, false, true)},
//        {"varchar",MdbTypeConstraints(false, false, true)},
//        {"BLOB",MdbTypeConstraints(false, false, true)},
//        {"TEXT",MdbTypeConstraints(false, false, true)},
//        {"BLOB",MdbTypeConstraints(false, false, true)},
//        {"BLOB",MdbTypeConstraints(false, false, true)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//        {"INTEGER",MdbTypeConstraints(false, false, false)},
//};