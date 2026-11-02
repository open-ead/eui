#pragma once

#include <euiAnimator.h>
#include <euiButtonBase.h>
#include <math/seadVector.h>

namespace nn::ui2d {
class ControlSrc;
class Pane;
}

namespace sead {
class Heap;
}

namespace eui {

class AnimatorSet;
class LayoutEx;

class AnimButton : public ButtonBase {
public:
    virtual const char* getClassName() const override { return "AnimButton"; }

    AnimButton();

    virtual void Build(const nn::ui2d::ControlSrc& controlSrc, LayoutEx* layout);
    void SetTouch(bool isTouch);
    virtual void BuildStateAnim(const nn::ui2d::ControlSrc& controlSrc, LayoutEx* layout);
    void DownOff(bool isDownOff);
    void Down();
    virtual bool HitTest(const sead::Vector2f& touchPos) const;
    virtual void StartDrag(const sead::Vector2f& touchPos);
    virtual void UpdateDrag(const sead::Vector2f* touchPos);
    virtual void FinishDrag(const sead::Vector2f* touchPos);
    void PlayDisableAnim(bool isPlay);
    void SetDisableAnimDirect(bool isDisabled);
    bool IsPlayDisableAnim() const;
    virtual void ActivateByBoxCursor();
    virtual void InactivateByBoxCursor();
    void ForceOff();
    void SelectStateAnim(s32 index);
    void ForceOn();
    void ForceDown();
    void StartOn() override;
    void StartOff() override;
    void StartDown() override;
    bool UpdateOn() override;
    bool UpdateOff() override;
    bool UpdateDown() override;
    void ProcessOn() override;
    void ProcessOff() override;
    void ProcessCancel() override;
    void FinishDown() override;
    void ChangeState(State state) override;
    void ForceChangeState(State state) override;

    const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override;

protected:
    void CloneImpl_(const AnimButton& other, LayoutEx* layout, sead::Heap* heap);

    AnimatorSet* mStateAnimatorSet = nullptr;
    Animator* mDisableAnimator = nullptr;
    nn::ui2d::Pane* mHitPane = nullptr;
    void* mBoxCursorControl = nullptr;
};

static_assert(sizeof(AnimButton) == 0x68);

}  // namespace eui
