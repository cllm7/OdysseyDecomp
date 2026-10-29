#pragma once

#include <basis/seadTypes.h>

namespace al {
class AudioEffectLevelDetector;

class SeGroupVolumeKeeper {
public:
    SeGroupVolumeKeeper(AudioEffectLevelDetector*);

    void update(bool);
    f32 getVolumeAtmos() const;
    f32 getVolumeAtmosObj() const;
    f32 getVolumePlayerVoice() const;
    f32 getVolumePlayer() const;

private:
    AudioEffectLevelDetector* mLevelDirector;
    f32 mRatio = 0.0f;
    f32 mDecibel = -96.0f;
    bool mIsBool10 = false;
    bool mIsBool11 = false;
};

static_assert(sizeof(SeGroupVolumeKeeper) == 0x18);
}  // namespace al
