#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class AudioEffectLevelDetector {
public:
    const sead::Vector2f& getLevel() const { return mLevel; }

private:
    char filler[0x98];
    sead::Vector2f mLevel;
};
}  // namespace al
