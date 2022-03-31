#include<hgl/audio/OpenAL.h>
#include<hgl/audio/AudioBuffer.h>
#include<hgl/audio/AudioSource.h>
#include<hgl/log/LogInfo.h>
#include<hgl/Time.h>

using namespace hgl;
using namespace openal;

int main(int,char **)
{
	if(!InitOpenAL( nullptr,		//��������
					nullptr,		//�豸����
					true,			//�Ƿ����debug��Ϣ
					false))			//�Ƿ�ö���豸��Ϣ
	{
		return(-1);
	}

	AudioBuffer buffer;
	
    double start=GetDoubleTime();
    double end;

	if(!buffer.Load(OS_TEXT("data\\cicada3.ogg"),AudioFileType::Vorbis))
	{
		LOG_ERROR(OS_TEXT("load audio file <cicada3.ogg> failed."));
		return(-2);
	}
    
	end=GetDoubleTime();

	LOG_INFO(u8"Audio Total time: "+UTF8String::valueOf(buffer.GetTime())+UTF8String(" Decode Time: ")+UTF8String::valueOf(end-start));

	AudioSource source;
	
    source.Link(&buffer);

    source.Play();

    WaitTime(buffer.GetTime());

	source.Close();
	buffer.Clear();

	CloseOpenAL();
}
