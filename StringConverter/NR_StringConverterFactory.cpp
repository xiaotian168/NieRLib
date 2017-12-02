
#define _NIER_API

#include "NR_StringConverterFactory.h"
#include "NR_CWin32StringConverter.h"
#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

NR_IStringConverter * MakeWin32StringConverter(void)
{
	return NR_CWin32StringConverter::Make();
}

#endif

NR_IStringConverter * MakeStringConverterByOSPlatform(void)
{
#if defined NIER_PLATFORM_WIN32
	return NR_CWin32StringConverter::Make();
#endif

	return 0;
}
