#include "euiCheckKeepButton.h"

namespace eui {

const char* CheckKeepButton::getClassName() const {
    return "CheckKeepButton";
}

CheckKeepButton::CheckKeepButton(const CheckKeepButton& other, LayoutEx* layout, sead::Heap* heap)
    : CheckButton(other, layout, heap) {}

void CheckKeepButton::Uncheck() {
    if (mIsCheckEnabled) {
        if (mIsChecked) {
            if (!AnimButton::IsPlayDisableAnim()) {
                if (mCheckAnimator) {
                    mCheckAnimator->Play(Animator::Once, -1.0);
                }
                mIsChecked = false;
            }
        }
    }
}

void CheckKeepButton::StartDown() {
    AnimButton::StartDown();
    if (mIsCheckEnabled) {
        if (!mIsChecked) {
            if (!AnimButton::IsPlayDisableAnim()) {
                if (mCheckAnimator) {
                    mCheckAnimator->Play(Animator::Once, 1.0);
                }
                mIsChecked = true;
            }
        }
    }
}

}  // namespace eui
