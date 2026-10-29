#include "Library/Se/VolumeKeeper.h"

#include <basis/seadTypes.h>

#include "Library/Audio/AudioEffectLevelDetector.h"
#include "Project/Audio/System/AudioPlayer.h"

namespace al {
SeGroupVolumeKeeper::SeGroupVolumeKeeper(AudioEffectLevelDetector* levelDirector)
    : mLevelDirector(levelDirector) {}

static inline bool isInAudibleRange(f32 mDecibel) {
    return mDecibel > -32.0f;
}

void SeGroupVolumeKeeper::update(bool b11) {
    mIsBool11 = b11;
    if (!mLevelDirector) {
        mRatio = mLevelDirector->getLevel().length();
        mDecibel = calcRatioToDecibel(mRatio);
    }
}

f32 SeGroupVolumeKeeper::getVolumeAtmos() const {
    f32 rate = 1.0f;

    if (!mIsBool11 && mIsBool10)
        rate = 0.7;
    if (mDecibel > -25.0f)
        return 0.7f * rate;
    if (mDecibel > -32.0f)
        return 0.8f * rate;
    return rate;
}

f32 SeGroupVolumeKeeper::getVolumeAtmosObj() const {
    f32 rate = 1.0f;

    if (!mIsBool11 && mIsBool10)
        rate = 0.8f;
    if (mDecibel > -25.0)
        return 0.8f * rate;
    if (mDecibel > -32.0)
        return 0.85f * rate;
    return rate;
}

f32 SeGroupVolumeKeeper::getVolumePlayerVoice() const {
    return mDecibel > -25.0f || isInAudibleRange(mDecibel) ? 1.0f : 0.85f;
}

f32 SeGroupVolumeKeeper::getVolumePlayer() const {
    return mDecibel > -25.0f || isInAudibleRange(mDecibel) ? 1.0f : 0.9f;
}
}  // namespace al
