#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "stdafx.h"
#include "SoundPlayer.h"
#include "SoundCallbackHander.h"

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")

SoundPlayer::SoundPlayer()
{
	uint32_t sampleRate = 44100;
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	HRESULT hr;

	m_sampleBits = 32;    // 32 for IEEE float

						  //TODO: обработать
	XAudio2Create(&m_audioEngine, 0);

	//TODO: обработать
	m_audioEngine->CreateMasteringVoice(&m_masterVoice);

	LoadSamples(sampleRate);
}

struct SoundPlayer::ImplData
{
	ImplData::ImplData(XAUDIO2_BUFFER  playData) :
		sourceVoice(nullptr),
		playData(playData),
		isPlaying(false),
		callbackHander(&isPlaying)
	{
	}

	~ImplData()
	{
		if (sourceVoice)
		{
			sourceVoice->DestroyVoice();
			sourceVoice = nullptr;
		}
	}

	IXAudio2SourceVoice* sourceVoice;
	XAUDIO2_BUFFER  playData;
	bool isPlaying;
	SoundCallbackHander callbackHander;
};

void SoundPlayer::LoadSamples(uint32_t sampleRate)
{
	for (std::map<int, float>::iterator i = noteFrequencues.begin(); i != noteFrequencues.end(); ++i)
	{
		AddSound(&GetWaveFormatex(sampleRate), &GetAudioBuffer(i->second));
	}
}

WAVEFORMATEX SoundPlayer::GetWaveFormatex(uint32_t sampleRate)
{
	int channels = 2;
	WAVEFORMATEX wfx;
	wfx.wBitsPerSample = m_sampleBits;
	wfx.nAvgBytesPerSec = sampleRate * channels * m_sampleBits / 8;
	wfx.nChannels = channels;
	wfx.nBlockAlign = channels * m_sampleBits / 8;
	wfx.wFormatTag = WAVE_FORMAT_IEEE_FLOAT; // or could use WAVE_FORMAT_PCM
	wfx.nSamplesPerSec = sampleRate;
	wfx.cbSize = 0;    // set to zero for PCM or IEEE float
	return wfx;
}

XAUDIO2_BUFFER SoundPlayer::GetAudioBuffer(float noteFrequency) 
{
	XAUDIO2_BUFFER m_buffer;
	m_buffer.AudioBytes = VOICE_BUFFER_SAMPLE_COUNT * 2;// *m_sampleBits / 8;
	m_buffer.PlayBegin = 0;
	m_buffer.PlayLength = 0;
	m_buffer.LoopBegin = 0;
	m_buffer.LoopLength = 0;
	m_buffer.LoopCount = 1;
	m_buffer.pAudioData = SineGenerate(noteFrequency);
	m_buffer.pContext = NULL;
	m_buffer.Flags = XAUDIO2_END_OF_STREAM;
	return m_buffer;
}

BYTE* SoundPlayer::SineGenerate(float& noteFrequency)
{
	float* m_bufferData = new float[VOICE_BUFFER_SAMPLE_COUNT]();
	float pi = 3.14159265;
	for (int i = 0; i < VOICE_BUFFER_SAMPLE_COUNT; i += 2)
	{
		m_bufferData[i] = m_bufferData[i + 1] = sin((float)(i * pi * 2 * noteFrequency) / (VOICE_BUFFER_SAMPLE_COUNT * 2));
	}
	return (BYTE *) m_bufferData;
}

size_t SoundPlayer::AddSound(	WAVEFORMATEX*  format,	XAUDIO2_BUFFER*   data)
{
	std::shared_ptr<ImplData> implData(new ImplData(*data));

	//TODO: обработать
	m_audioEngine->CreateSourceVoice(
		&implData->sourceVoice,
		format,
		0,
		XAUDIO2_DEFAULT_FREQ_RATIO,
		reinterpret_cast<IXAudio2VoiceCallback*>(&implData->callbackHander),
		nullptr,
		nullptr
	);
	m_soundList.push_back(implData);
	return (m_soundList.size() - 1);
}

bool SoundPlayer::PlaySound(size_t index)
{
	std::shared_ptr<ImplData> soundData = m_soundList[index];
	XAUDIO2_BUFFER playBuffer = soundData->playData;
	playBuffer.Flags = XAUDIO2_END_OF_STREAM;

	HRESULT hr = soundData->sourceVoice->Stop();
	if (SUCCEEDED(hr))
	{
		hr = soundData->sourceVoice->FlushSourceBuffers();
	}

	hr = soundData->sourceVoice->SubmitSourceBuffer(&playBuffer);
	if (SUCCEEDED(hr))
	{
		hr = soundData->sourceVoice->Start(0, XAUDIO2_COMMIT_NOW);
	}
	
	return SUCCEEDED(hr);
}

bool SoundPlayer::StopSound(size_t index)
{
	std::shared_ptr<ImplData> soundData = m_soundList[index];

	HRESULT hr = soundData->sourceVoice->Stop();
	if (SUCCEEDED(hr))
	{
		hr = soundData->sourceVoice->FlushSourceBuffers();
	}

	return SUCCEEDED(hr);
}
