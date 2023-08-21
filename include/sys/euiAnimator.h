#pragma once

#include <nn/font/font_Util.h>

#include <nn/ui2d/ui2d_Animation.h>
#include <nn/ui2d/ui2d_Group.h>
#include <nn/ui2d/ui2d_Pane.h>

#include <eui/lytex/euiLayoutEx.h>

namespace eui {

class Animator : public AnimTransformBasic {
public:
    NN_RUNTIME_TYPEINFO_BASE();

    enum PlayType {
        PLAYTYPE_ONESHOT,
        PLAYTYPE_LOOP,
        PLAYTYPE_ROUNDTRIP
    };

    Animator();
    virtual ~Animator();

    virtual void Play(PlayType type, f32 speed);
    virtual void PlayAuto(f32 speed);
    virtual void PlayFromCurrent(PlayType type, f32 speed);
    virtual void PlayRandom(PlayType type, f32 speed);
    virtual void SetEnabled(bool bEnabled);

    virtual void SetupBasic(const AnimResource &animRes, LayoutEx *pLayoutEx, bool enabled);
    virtual void SetupWithGroup(const AnimResource &animRes, LayoutEx *pLayoutEx, Group *pGroup, bool enabled);
    virtual void SetupWithGroupAll(const AnimResource &animRes, LayoutEx *pLayoutEx, GroupContainer *pGroupCont, bool enabled);
    virtual void SetupWithGroupIndex(const AnimResource &animRes, LayoutEx *pLayoutEx, GroupContainer *pGroupCont, u32 idx, bool enabled);
    virtual void SetupWithPane(const AnimResource &animRes, LayoutEx *pLayoutEx, Pane *pPane, bool enabled);

    virtual void Stop(f32 frame);
    virtual void StopAtMin();
    virtual void StopAtMax();
    virtual void StopCurrent();
    virtual void Synchronize(const Animator &animator);
    virtual void UpdateFrame(f32 progress_frame);
}
}