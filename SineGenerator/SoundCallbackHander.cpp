#include "stdafx.h"
#include "SoundCallbackHander.h"

void SoundCallbackHander::OnVoiceProcessingPassStart(UINT32 /*bytesRequired*/)
{
}
void SoundCallbackHander::OnVoiceProcessingPassEnd()
{
}
void SoundCallbackHander::OnStreamEnd()
{
}
void SoundCallbackHander::OnBufferStart(void* /*bufferContext*/)
{
	*m_isPlayingHolder = true;
}
void SoundCallbackHander::OnBufferEnd(void* /*bufferContext*/)
{
	*m_isPlayingHolder = false;
}
void SoundCallbackHander::OnLoopEnd(void* /*bufferContext*/)
{
}
void SoundCallbackHander::OnVoiceError(void* /*bufferContext*/, HRESULT /*error*/)
{
}