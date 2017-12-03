
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
** @brief �ر�����ӵ��ָ�����ƵĽ���
** @param pszProcessName Ҫ�رյĽ�����
** @param uExitCode �����˳���
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode);
NR_CAPI bool NR_ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode);

/**
** @brief ��ȡ��ǰ����ģ���ļ�����·��
*/
NR_CAPI bool NR_GetCurrentModuleFileNameW(wchar_t * pszName, const unsigned int uSize);
NR_CAPI bool NR_GetCurrentModuleFileNameA(char * pszName, const unsigned int uSize);

/**
** @brief ͨ���������ƣ���ȡ���� ID
*/
NR_CAPI bool NR_GetProcessIDByProcessNameW(const wchar_t * pszProcessName, std::list<NR_IProcess::IDType> & IDList);
