#pragma once

#include <basis/seadTypes.h>

namespace nn::font::detail {
class RuntimeTypeInfo;
}

namespace nn::ui2d {
class AnimResource;
class Group;
class GroupContainer;
class Pane;
}

namespace sead {
class Heap;
}

namespace eui {

class LayoutEx;

class AnimatorVtableBase {
public:
    virtual ~AnimatorVtableBase();

    virtual void _10();
    virtual void _18();
    virtual void _20();
    virtual void _28();
    virtual void _30();
    virtual void _38();
    virtual void _40();
    virtual void _48();
    virtual void _50();
    virtual void _58();
    virtual void _60();
    virtual void _68();
    virtual void _70();
    virtual void _78();
    virtual void _80();
    virtual void _88();
    virtual void _90();
    virtual void _98();
    virtual void _a0();
};

class Animator : public AnimatorVtableBase {
public:
    enum PlayType : s32 {
        Once = 0,
        Loop = 1,
    };

    Animator();
    ~Animator() override;

    void SetupBasic(const nn::ui2d::AnimResource& resource, LayoutEx* layout, bool isEnabled);
    void SetupWithPane(const nn::ui2d::AnimResource& resource, LayoutEx* layout,
                       nn::ui2d::Pane* pane, bool isEnabled);
    void SetupWithGroup(const nn::ui2d::AnimResource& resource, LayoutEx* layout,
                        nn::ui2d::Group* group, bool isEnabled);
    void SetupWithGroupIndex(const nn::ui2d::AnimResource& resource, LayoutEx* layout,
                             nn::ui2d::GroupContainer* container, u32 groupIndex,
                             bool isEnabled);
    void SetupWithGroupAll(const nn::ui2d::AnimResource& resource, LayoutEx* layout,
                           nn::ui2d::GroupContainer* container, bool isEnabled);

    virtual bool Play(PlayType playType, f32 frame);
    virtual bool PlayAuto(f32 frame);
    virtual bool PlayFromCurrent(PlayType playType, f32 frame);
    virtual bool PlayFromFrame(f32 startFrame, PlayType playType, f32 frame);
    virtual bool PlayRandom(PlayType playType, f32 frame);

    void Synchronize(const Animator& other);
    void Stop(f32 frame);
    void StopCurrent();

    virtual void StopAtMin();
    virtual void StopAtMax();
    virtual void SetEnabled(bool isEnabled);
    virtual void DisableAndEraseFromActiveList();
    virtual void UpdateFrame(f32 delta);
    virtual const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const;
};

}  // namespace eui
