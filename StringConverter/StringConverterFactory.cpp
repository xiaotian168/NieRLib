
#define _NIER_API

#include "StringConverterFactory.h"
#include "CWin32StringConverter.h"
#include "../NieRLibConfig.h"

IStringConverter * MakeWin32StringConverter(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32StringConverter::Make();
#endif

	return 0;
}

IStringConverter * MakeStringConverterByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return CWin32StringConverter::Make();
#endif

	return 0;
}
