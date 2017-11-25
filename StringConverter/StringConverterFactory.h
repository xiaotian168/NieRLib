
#pragma once

#include "../NieRLibConfig.h"

class IStringConverter;

/**
** @brief 创建 Win32 字符串转换器
** @return Win32 字符串转换器
*/
NIER_CAPI IStringConverter * MakeWin32StringConverter(void);

/**
** @brief 自动根据调用者所在平台，创建字符转换器
** @return 字符转换器
*/
NIER_CAPI IStringConverter * MakeStringConverterByOSPlatform(void);
