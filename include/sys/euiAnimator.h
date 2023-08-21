#pragma once

#include <nn/font/font_Util.h>
#include <nn/ui2d/ui2d_Pane.h>

namespace nn {
namespace ui2d {
    class Group;
    class AnimTransformBasic;
    class AnimResource;
}
}

namespace eui {
class LayoutEx;

class Animator : public nn::ui2d::AnimTransformBasic {
public:
    NN_RUNTIME_TYPEINFO(AnimTransformBasic);

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

    virtual void SetupBasic(const nn::ui2d::AnimResource &animRes, eui::LayoutEx *pLayoutEx, bool enabled);
    virtual void SetupWithGroup(const nn::ui2d::AnimResource &animRes, eui::LayoutEx *pLayoutEx, nn::ui2d::Group *pGroup, bool enabled);
    virtual void SetupWithGroupAll(const nn::ui2d::AnimResource &animRes, eui::LayoutEx *pLayoutEx, nn::ui2d::GroupContainer *pGroupCont, bool enabled);
    virtual void SetupWithGroupIndex(const nn::ui2d::AnimResource &animRes, eui::LayoutEx *pLayoutEx, nn::ui2d::GroupContainer *pGroupCont, u32 idx, bool enabled);
    virtual void SetupWithPane(const nn::ui2d::AnimResource &animRes, eui::LayoutEx *pLayoutEx, nn::ui2d::Pane *pPane, bool enabled);

    virtual void Stop(f32 frame);
    virtual void StopAtMin();
    virtual void StopAtMax();
    virtual void StopCurrent();
    virtual void Synchronize(const eui::Animator &animator);
    virtual void UpdateFrame(f32 progress_frame);
}
}
