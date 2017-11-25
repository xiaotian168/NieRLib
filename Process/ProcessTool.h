
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
