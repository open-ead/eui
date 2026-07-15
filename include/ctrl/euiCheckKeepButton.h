#pragma once

#include <euiCheckButton.h>

namespace sead {
class Heap;
}

namespace eui {

class LayoutEx;

class CheckKeepButton : public CheckButton {
public:
    const char* getClassName() const override;

    CheckKeepButton(const CheckKeepButton& other, LayoutEx* layout, sead::Heap* heap);

    void Uncheck();
    void StartDown() override;

    const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override {
        static const nn::font::detail::RuntimeTypeInfo s_TypeInfo(
            CheckButton::GetRuntimeTypeInfoStatic());
        return &s_TypeInfo;
    }
};

static_assert(sizeof(CheckKeepButton) == 0x78);

}  // namespace eui
