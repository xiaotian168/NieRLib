
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define ShutdownProcessByName ShutdownProcessByNameW
#else
#	define ShutdownProcessByName ShutdownProcessByNameA
#endif

/**
** @brief �ر�����ӵ��ָ�����ƵĽ���
** @param pszProcessName Ҫ�رյĽ�����
** @param uExitCode �����˳���
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NIER_CAPI bool ShutdownProcessByNameW(const wchar_t * pszProcessName, const unsigned int uExitCode);
NIER_CAPI bool ShutdownProcessByNameA(const char * pszProcessName, const unsigned int uExitCode);

/**
** @brief ��ȡ��ǰ����ģ������
*/
NIER_CAPI bool GetCurrentModuleNameW(wchar_t * pszName, const unsigned int uSize);
NIER_CAPI bool GetCurrentModuleNameA(char * pszName, const unsigned int uSize);
