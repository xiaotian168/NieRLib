
#pragma once

#include "../NieRLibConfig.h"
#include "NR_IProcess.h"

#if defined UNICODE || defined _UNICODE
#	define NR_ShutdownProcessByName NR_ShutdownProcessByNameW
#	define NR_GetCurrentModuleFileName NR_GetCurrentModuleFileNameW
#else
#	define NR_ShutdownProcessByName NR_ShutdownProcessByNameA
#	define NR_GetCurrentModuleFileName NR_GetCurrentModuleFileNameA
#endif

/**
** @brief 关闭所有拥有指定名称的进程
** @param pszProcessName 要关闭的进程名
** @param uExitCode 进程退出码
** @return true 表示成功，false 表示失败
*/
NR_CAPI bool NR_ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode);
NR_CAPI bool NR_ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode);

/**
** @brief 获取当前进程模块文件完整路径
*/
NR_CAPI bool NR_GetCurrentModuleFileNameW(wchar_t * pszName, const unsigned int uSize);
NR_CAPI bool NR_GetCurrentModuleFileNameA(char * pszName, const unsigned int uSize);

/**
** @brief 通过进程名称，获取进程 ID
*/
NR_CAPI bool NR_GetProcessIDByProcessNameW(const wchar_t * pszProcessName, std::list<NR_IProcess::IDType> & IDList);
