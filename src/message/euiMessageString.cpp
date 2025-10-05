#include "message/euiMessageString.h"

#include <prim/seadSafeString.h>

namespace eui {

MessageString::MessageString() {
    mStr = nullptr;
    mStrLen = 0;
}

MessageString::MessageString(s32 len, const char16_t* str) {
    mStr = str;
    mStrLen = len;
}

MessageString::MessageString(const char16_t* str, const char16_t* str2) {
    mStr = str;
    mStrLen = (str2 - str);
}

MessageString::MessageString(const sead::SafeStringBase<char16_t>& str) {
    mStr = str.cstr();
    mStrLen = str.calcLength();
}

MessageString::MessageString(const MessageString& str) {
    mStr = str.getStr();
    mStrLen = str.getStrLen();
}

void MessageString::operator=(const MessageString& str) {
    mStr = str.getStr();
    mStrLen = str.getStrLen();
}

const char16_t* MessageString::operator[](s32 i) const {
    return mStrLen <= i ? &mStr[0] : &mStr[i];
}

MessageString::iterator MessageString::begin() const {
    return { mStr };
}

MessageString::iterator MessageString::end() const {
    return { 
        mStr,
        mStrLen
    };
}

MessageString::iterator MessageString::toIterator(s32 len) const {
    u32 size = mStrLen <= len ? mStrLen : len;
    return {
        mStr,
        size
    };
}

} // namespace eui
