
#pragma once

#include "../NieRLibConfig.h"

class NR_ILibrary;

/**
** @brief ���ؿ�
** @param pszLibraryPath ���ļ�·��
** @return ��
*/
NR_CAPI NR_ILibrary * NR_GetLibraryW(const wchar_t * pszLibraryPath);
