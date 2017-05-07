// SoundPlayer.cpp : Defines the entry point for the console application.
//

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "stdafx.h"
#include "SoundPlayer.h"

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")

SoundPlayer::SoundPlayer(float noteFrequency)
{
	uint32_t sampleRate = 44100;
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	HRESULT hr;

	m_sampleBits = 32;    // 32 for IEEE float

	//TODO: обработать
	XAudio2Create(&m_audioEngine, 0);

	//TODO: обработать
	m_audioEngine->CreateMasteringVoice(&m_masterVoice);


	int channels = 2;
	//set up wave format using my good friend WAVEFORMATEX
	WAVEFORMATEX wfx;
	wfx.wBitsPerSample = m_sampleBits;
	wfx.nAvgBytesPerSec = sampleRate * channels * m_sampleBits / 8;
	wfx.nChannels = channels;
	wfx.nBlockAlign = channels * m_sampleBits / 8;
	wfx.wFormatTag = WAVE_FORMAT_IEEE_FLOAT; // or could use WAVE_FORMAT_PCM
	wfx.nSamplesPerSec = sampleRate;
	wfx.cbSize = 0;    // set to zero for PCM or IEEE float

	//TODO: обработать
	m_audioEngine->CreateSourceVoice(&m_voice, &wfx, XAUDIO2_VOICE_USEFILTER);

	PlaySound(noteFrequency);

	//TODO: в деструктор
	m_voice->DestroyVoice();
}

bool SoundPlayer::PlaySound(float noteFrequency)
{
	SineGenerate(noteFrequency, m_bufferData);

	m_buffer.AudioBytes = VOICE_BUFFER_SAMPLE_COUNT * 2;// *m_sampleBits / 8;
	m_buffer.PlayBegin = 0;
	m_buffer.PlayLength = 0;    
	m_buffer.LoopBegin = 0;
	m_buffer.LoopLength = 0;    
	m_buffer.LoopCount = 1;
	m_buffer.pAudioData = (BYTE *)&m_bufferData;
	m_buffer.pContext = NULL;
	m_buffer.Flags = XAUDIO2_END_OF_STREAM;

	HRESULT hr = m_voice->SubmitSourceBuffer(&m_buffer);
	if (SUCCEEDED(hr))
	{
		hr = m_voice->Start(0, XAUDIO2_COMMIT_NOW);
	}

	BOOL isRunning = TRUE;
	while (isRunning)
	{
		XAUDIO2_VOICE_STATE state;
		m_voice->GetState(&state);
		isRunning = (state.BuffersQueued > 0) != 0;

		// Wait till the escape key is pressed
		if (GetAsyncKeyState(VK_ESCAPE))
			break;

		Sleep(10);
	}

	return hr;
}

//void SoundPlayer::AddSound(float noteFrequency)
//{
//	m_audioEngine->CreateSourceVoice(&m_voice, &wfx, XAUDIO2_VOICE_USEFILTER);
//}

void SoundPlayer::SineGenerate(float noteFrequency, float *m_bufferData)
{
	//TODO: Ќайти более элегантное пи
	float pi = 3.14159265;
	for (int i = 0; i < VOICE_BUFFER_SAMPLE_COUNT; i += 2)
	{
		m_bufferData[i] = m_bufferData[i + 1] = sin(i * pi * 2 * noteFrequency / (VOICE_BUFFER_SAMPLE_COUNT * 2));
	}
}

