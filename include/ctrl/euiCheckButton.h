#pragma once

#include <euiAnimButton.h>

namespace nn::ui2d {
class ControlSrc;
}

namespace sead {
class Heap;
}

namespace eui {

class LayoutEx;

class CheckButton : public AnimButton {
public:
    virtual const char* getClassName() const override { return "CheckButton"; }

    CheckButton(const CheckButton& other, LayoutEx* layout, sead::Heap* heap);

    void Build(const nn::ui2d::ControlSrc& controlSrc, LayoutEx* layout) override;
    void ForceSetChecked(bool isChecked);
    void StartDown() override;
    bool UpdateDown() override;

    static const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfoStatic();
    const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override {
        return GetRuntimeTypeInfoStatic();
    }

protected:
    bool mIsChecked = false;
    bool mIsCheckEnabled = false;
    Animator* mCheckAnimator = nullptr;
};

static_assert(sizeof(CheckButton) == 0x78);

}  // namespace eui
