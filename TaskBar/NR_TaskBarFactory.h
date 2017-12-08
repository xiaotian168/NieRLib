
#pragma once

#include "../NieRLibConfig.h"

class NR_ITaskBarInfo;

#if defined NR_PLATFORM_WIN32

/**
** @brief 创建 Win32 任务栏信息接口
** @return Win32 任务栏信息接口
*/
NR_CAPI NR_ITaskBarInfo * NR_MakeWin32TaskBarInfo(void);

#endif

/**
** @brief 自动根据调用者所在平台，创建任务栏信息接口
** @return 任务栏信息接口
*/
NR_CAPI NR_ITaskBarInfo * NR_MakeTaskBarInfoByOSPlatform(void);
