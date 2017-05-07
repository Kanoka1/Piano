#pragma once

#include <xaudio2.h>
#include <xaudio2fx.h>
#include "pch.h"

#define VOICE_BUFFER_SAMPLE_COUNT (44100)

class SoundPlayer sealed
{
private:
	int m_sampleBits;

	IXAudio2MasteringVoice* m_masterVoice;    // cannot use ComPtr for this
	IXAudio2* m_audioEngine;


	// this is temp stuff which will be rolled into another class
	IXAudio2SourceVoice* m_voice;
	XAUDIO2_BUFFER m_buffer;
	IXAudio2* pXAudio2;
	float m_bufferData[VOICE_BUFFER_SAMPLE_COUNT];

	void SineGenerate(float noteFrequency, float *m_bufferData);
	bool PlaySound(float noteFrequency);
	void AddSound();

public:
	SoundPlayer(float noteFrequency);

}; 