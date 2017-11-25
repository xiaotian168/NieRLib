
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define ShutdownProcessByName ShutdownProcessByNameW
#else
#	define ShutdownProcessByName ShutdownProcessByNameA
#endif

/**
** @brief 关闭所有拥有指定名称的进程
** @param pszProcessName 要关闭的进程名
** @param uExitCode 进程退出码
** @return true 表示成功，false 表示失败
*/
NIER_CAPI bool ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode);
NIER_CAPI bool ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode);
