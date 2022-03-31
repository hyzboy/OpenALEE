#include<hgl/audio/OpenAL.h>
#include<hgl/audio/AudioBuffer.h>
#include<hgl/audio/AudioSource.h>
#include<hgl/log/LogInfo.h>
#include<hgl/Time.h>

using namespace hgl;
using namespace openal;

int main(int,char **)
{
	if(!InitOpenAL( nullptr,		//驱动名称
					nullptr,		//设备名称
					true,			//是否输出debug信息
					false))			//是否枚举设备信息
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
