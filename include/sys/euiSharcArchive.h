#pragma once

#include <basis/seadTypes.h>

namespace sead {
class Heap;
}

namespace eui {

class SharcArchive {
public:
    class FileReader;

    SharcArchive();

    void finalize();
    void initialize(sead::Heap*, void*, u32);
    void startFileReader(eui::SharcArchive::FileReader*) const;

private:
    char _filler[0x8];
};

static_assert(sizeof(SharcArchive) == 0x8);

}  // namespace eui
