
#define _NIER_API

#include "CWin32StringConverter.h"
#include "../NieRLibConfig.h"

IStringConverter * MakeWin32StringConverter(void)
{
	return CWin32StringConverter::Make();
}

IStringConverter * MakeStringConverterByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32 || defined NIER_PLATFORM_LINUX
	return CWin32StringConverter::Make();
#endif

	return 0;
}
