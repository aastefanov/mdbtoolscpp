#include <schema/mdbschema.h>

using namespace mdbtools::schema;

namespace mdbtools {
    class MdbFile {
    private:
        MdbHandle *handle;
    public:
        void Open(const char *filename, MdbFileFlags flags) {
            handle = new MdbHandle();
            handle->default_backend
        }

        void Close() {
            delete handle;
        }
    };
}