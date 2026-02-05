#pragma once

#include <basis/seadTypes.h>
#include <container/seadBuffer.h>
#include <prim/seadSafeString.h>

#include "sys/euiSharcArchive.h"

namespace sead {
class Heap;
}

namespace nn::font {
class Font;
class ResFont;
}  // namespace nn::font

namespace eui {
class ScalableFontMgr;

class FontMgr {
    SEAD_SINGLETON_DISPOSER(FontMgr)
public:
    FontMgr();

    void initialize(sead::Heap*, void*, u32, const sead::Buffer<const char*>&,
                    eui::ScalableFontMgr*);
    void finalize();
    void registFont(nn::ui2d::ResourceAccessor*);
    const nn::font::Font* tryGetFont(const sead::SafeString&) const;
    nn::font::Font* tryGetFont(const sead::SafeString&);
    const nn::font::Font* getFont(const sead::SafeString&) const;
    nn::font::Font* getFont(const sead::SafeString&);
    const nn::font::Font* getFontByMessageIndex(u32) const;
    nn::font::Font* getFontByMessageIndex(u32);
    void setRubyFont(const sead::SafeString&);
    void setRubyFont(const nn::font::Font*);
    bool isScalableFont(const sead::SafeString&) const;
    void findFontName(sead::BufferedSafeString*, const nn::font::Font*) const;

    ScalableFontMgr* getScalableFontMgr() const { return mScalableFontMrg; }

private:
    char filler[0x8];
    SharcArchive mSharcArchive;
    sead::PtrArray<nn::font::ResFont> _30;
    sead::PtrArray<nn::font::Font> _40;
    nn::font::Font* mRubyFont;
    ScalableFontMgr* mScalableFontMrg;
};

static_assert(sizeof(FontMgr) == 0x60);

}  // namespace eui
