#pragma once

#include <basis/seadTypes.h>
#include <euiControlBase.h>

namespace eui {

class ButtonBase : public ControlBase {
public:
    enum State : s32 {
        State_Off = 0,
        State_On = 1,
        State_Down = 2,
        State_Cancel = 3,
    };

    enum Action : s32 {
        Action_Off = 0,
        Action_On = 1,
        Action_Down = 2,
        Action_Cancel = 3,
    };

    struct ActionQueue {
        void PushWithOmit(Action action);
        Action Pop();
        bool IsDownExist() const;

        u8 mActions[4] = {};
        s32 mCount = 0;
    };

    virtual const char* getClassName() const { return "ButtonBase"; }

    ButtonBase();

    void On();
    void ResumeUpdate();
    void Off();
    void Down();
    void Cancel();
    void ForceOff();
    void ForceOn();
    void ForceDown();
    void Update(f32 delta) override;
    void ProcessActionFromQueue();
    void SetActive(bool isActive);

    virtual void ProcessOn();
    virtual void ProcessOff();
    virtual void ProcessDown();
    virtual void ProcessCancel();
    virtual bool UpdateOn();
    virtual bool UpdateOff();
    virtual bool UpdateDown();
    virtual bool UpdateCancel();
    virtual void StartOn();
    virtual void StartOff();
    virtual void StartDown();
    virtual void StartCancel();
    virtual void FinishOn();
    virtual void FinishOff();
    virtual void FinishDown();
    virtual void FinishCancel();
    virtual void ChangeState(State state);
    virtual void ForceChangeState(State state);

    bool IsDowning() const;

    const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const override;

private:
    void* mPrev = nullptr;
    void* mNext = nullptr;
    bool mIsActive = false;
    bool mIsUpdatePaused = false;
    u16 mFlags = 0x1F;
    ActionQueue mActionQueue;
};

static_assert(sizeof(ButtonBase::ActionQueue) == 0x8);
static_assert(sizeof(ButtonBase) == 0x48);

}  // namespace eui
