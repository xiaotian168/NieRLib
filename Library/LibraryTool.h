
#pragma once

#include "../NieRLibConfig.h"

class ILibrary;

/**
** @brief ���ؿ�
** @param pszLibraryPath ���ļ�·��
** @return ��
*/
NIER_CAPI ILibrary * GetLibraryW(const wchar_t * pszLibraryPath);
