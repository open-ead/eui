#pragma once

#include <sead/gfx/seadColor.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/prim/seadSafeString.h>

namespace eui {

class MessageSet;

class MessageMgr {
    SEAD_RTTI_BASE(MessageMgr);
    SEAD_SINGLETON_DISPOSER(MessageMgr);
    MessageMgr();
    virtual ~MessageMgr();

public:
    class Archive;

public:
    virtual void loadArchive(sead::Heap*, void*, unsigned int);
    virtual void unloadArchive(void*);

    void initialize(sead::Heap*, unsigned int maxColors);
    void finalize();
    
    void archiveDisposeCallback_(Archive*);
    void dumpLastGotMessageSetInfo(); // Implementation requires some debug compiler flag

    void setGradationColor(unsigned int idx, sead::Color4u8 top, sead::Color4u8 bottom);
    void setTextBoxWidthSizeOverColor(sead::Color4u8);
    
    MessageSet* getLayoutMessageSet(sead::SafeString const&) const;
    MessageSet* getMessageSet(sead::SafeString const&) const;

private:
    char unk[0x30];
};

static_assert(sizeof(MessageMgr) == 0x58);

} // namespace eui
