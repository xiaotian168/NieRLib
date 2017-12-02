
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define NR_ShutdownProcessByName NR_ShutdownProcessByNameW
#else
#	define NR_ShutdownProcessByName NR_ShutdownProcessByNameA
#endif

/**
** @brief �ر�����ӵ��ָ�����ƵĽ���
** @param pszProcessName Ҫ�رյĽ�����
** @param uExitCode �����˳���
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NIER_CAPI bool NR_ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode);
NIER_CAPI bool NR_ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode);

/**
** @brief ��ȡ��ǰ����ģ���ļ�����·��
*/
NIER_CAPI bool NR_GetCurrentModuleFileNameW(wchar_t * pszName, const unsigned int uSize);
NIER_CAPI bool NR_GetCurrentModuleFileNameA(char * pszName, const unsigned int uSize);
