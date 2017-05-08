#pragma once

#include <xaudio2.h>
#include <xaudio2fx.h>
#include "pch.h"
#include <map>

#define VOICE_BUFFER_SAMPLE_COUNT (44100)

constexpr float FrequencyNoteC  = 261.63f; 
constexpr float FrequencyNoteCb = 277.18f;
constexpr float FrequencyNoteD = 293.66f;
constexpr float FrequencyNoteDb = 311.13f;
constexpr float FrequencyNoteE = 329.63f;
constexpr float FrequencyNoteF = 349.23f;
constexpr float FrequencyNoteFb = 369.99f;
constexpr float FrequencyNoteG = 392.00f;
constexpr float FrequencyNoteGb = 415.30f;
constexpr float FrequencyNoteA = 440.00f;
constexpr float FrequencyNoteAb = 466.16f;
constexpr float FrequencyNoteB = 493.88f;

class SoundPlayer sealed
{
private:
	struct ImplData;

	int m_sampleBits;

	IXAudio2MasteringVoice* m_masterVoice;    // cannot use ComPtr for this
	IXAudio2* m_audioEngine;


	// this is temp stuff which will be rolled into another class
	IXAudio2SourceVoice* m_voice;
	IXAudio2* pXAudio2;

	std::vector<std::shared_ptr<ImplData>>  m_soundList;

	void LoadSamples(uint32_t sampleRate);
	WAVEFORMATEX GetWaveFormatex(uint32_t sampleRate);
	size_t AddSound(_In_ WAVEFORMATEX* format, XAUDIO2_BUFFER* data);
	XAUDIO2_BUFFER GetAudioBuffer(float noteFrequency);
	BYTE* SineGenerate(float& noteFrequency);

	std::map<int, float> noteFrequencues
	{
		{ 0, FrequencyNoteC },
		{ 1, FrequencyNoteCb },
		{ 2, FrequencyNoteD },
		{ 3, FrequencyNoteDb },
		{ 4, FrequencyNoteE },
		{ 5, FrequencyNoteF },
		{ 6, FrequencyNoteFb },
		{ 7, FrequencyNoteG },
		{ 8, FrequencyNoteGb },
		{ 9, FrequencyNoteA },
		{ 10, FrequencyNoteAb },
		{ 11, FrequencyNoteB },
	};

public:
	SoundPlayer();
	bool StopSound(size_t index);
	bool PlaySound(size_t index);
}; 