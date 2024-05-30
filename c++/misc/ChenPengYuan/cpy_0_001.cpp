#include <iostream>

MyCallback::MyCallback(AudioParam param) : audioParam_(param) {
    frameDiv_ = sizeof(int16_t) * audioParam_.channelCount;
    //公式：数据率=采样频率(Hz)×量化位数(bit)×声道数(bit/s),在48000 Hz采样率下，如果是16位立体声，数据率将是 1536 kbps。
    audioDataRate = (audioParam_.sampleRate * audioParam_.AudioFormat * audioParam_.channelCount)/1000;
    bufferSize_ = audioDataRate * 50;
    frameBuffer_ = static_cast<uint8_t *>(malloc(bufferSize_));
}

MyCallback::~MyCallback() {
    free(frameBuffer_);
}

oboe::DataCallbackResult
MyCallback::onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) {
    auto *outputData = static_cast<int16_t *>(audioData);
    size_t waitLen = numFrames * frameDiv_;
    if ((frameCount_++ & 0xff) == 0) {
        LOGV("waitLen = %d, cachedSize_ = %d", waitLen, cachedSize_);
    }

    std::lock_guard<std::mutex> lock(mutex_);
    if (cachedSize_ < waitLen) {
        memset(outputData, 0, waitLen);
        memcpy(outputData, &frameBuffer_, cachedSize_);
        cachedSize_ = 0;
    } else {
        memcpy(outputData, &frameBuffer_, waitLen);
        cachedSize_ -= waitLen;
        memmove(frameBuffer_, frameBuffer_ + waitLen, cachedSize_);
    }
    return oboe::DataCallbackResult::Continue;
}