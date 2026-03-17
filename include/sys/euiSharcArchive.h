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
    ~SharcArchive();

    void finalize();
    void initialize(sead::Heap*, void*, u32);
    void startFileReader(eui::SharcArchive::FileReader*) const;

private:
    sead::Resource* mResource;
};

static_assert(sizeof(SharcArchive) == 0x8);

}  // namespace eui
