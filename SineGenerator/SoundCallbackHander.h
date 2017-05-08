#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "stdafx.h"
#include "SoundPlayer.h"

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")

class SoundCallbackHander : public IXAudio2VoiceCallback
{
public:
	SoundCallbackHander(bool* isPlayingHolder) :
		m_isPlayingHolder(isPlayingHolder)
	{
	}

	~SoundCallbackHander()
	{
		m_isPlayingHolder = nullptr;
	}

	//
	// Voice callbacks from IXAudio2VoiceCallback
	//
	STDMETHOD_(void, OnVoiceProcessingPassStart) (THIS_ UINT32 bytesRequired);
	STDMETHOD_(void, OnVoiceProcessingPassEnd) (THIS);
	STDMETHOD_(void, OnStreamEnd) (THIS);
	STDMETHOD_(void, OnBufferStart) (THIS_ void* bufferContext);
	STDMETHOD_(void, OnBufferEnd) (THIS_ void* bufferContext);
	STDMETHOD_(void, OnLoopEnd) (THIS_ void* bufferContext);
	STDMETHOD_(void, OnVoiceError) (THIS_ void* bufferContext, HRESULT error);

private:
	bool* m_isPlayingHolder;
};