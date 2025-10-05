#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>

namespace eui {

class MessageString {
public:
    class iterator {
    public:
        iterator(const char16_t* ptr, u32 index = 0) : mPtr(ptr), mIndex(index) {}
    
        
    private:
        const char16_t* mPtr;
        u32 mIndex;
    };

    MessageString();
    MessageString(s32 len, const char16_t* str);
    MessageString(const char16_t* str, const char16_t* str2);
    MessageString(const sead::SafeStringBase<char16_t>& str);
    MessageString(const MessageString& messageStr);

    void operator=(const MessageString& str);
    const char16_t* operator[](s32 i) const;

    iterator begin() const;
    iterator end() const;
    iterator toIterator(s32 len) const;
    bool tryMakeTagStrippedString(sead::BufferedSafeStringBase<char16_t>* str) const;

    const char16_t* getStr() const { return mStr; }
    s32 getStrLen() const { return mStrLen; }

private:
    const char16_t* mStr;
    u32 mStrLen;
};

} // namespace eui
