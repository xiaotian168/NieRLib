
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief ��ȡϵͳ��ʱĿ¼·��
*/
NR_CAPI bool NR_GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief ��ȡϵͳĿ¼·��
*/
NR_CAPI bool NR_GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize);

/**
** @brief ��ϵͳ��ʱĿ¼�д���һ����ʱ�ļ���
*/
NR_CAPI bool NR_MakeTempFilePathW(wchar_t * pszFilePath, const unsigned int uSize);
