
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief ��·���зָ��Ŀ¼�ɷ�
*/
NR_CAPI bool NR_SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief ��·�����Ƴ��ļ�������
*/
NR_CAPI bool NR_RemoveFileSpecW(wchar_t * pszPath);

/**
** @brief �Զ���·��ĩβ���б���ַ�
*/
NR_CAPI bool NR_AppendBackslashW(wchar_t * pszPath, const unsigned int uSize);
