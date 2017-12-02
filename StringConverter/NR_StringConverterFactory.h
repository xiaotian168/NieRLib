
#pragma once

#include "../NieRLibConfig.h"

class NR_IStringConverter;

#if defined NIER_PLATFORM_WIN32

/**
** @brief 创建 Win32 字符串转换器
** @return Win32 字符串转换器
*/
NIER_CAPI NR_IStringConverter * MakeWin32StringConverter(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建字符转换器
** @return 字符转换器
*/
NIER_CAPI NR_IStringConverter * MakeStringConverterByOSPlatform(void);
