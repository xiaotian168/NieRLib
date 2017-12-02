
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_ILibrary;

/**
** @brief ��ӹ�������
*/
class NR_ILibraryManager : public NR_IRefCount
{
public:

	/**
	** @brief ���ؿ�
	*/
	virtual NR_ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) = 0;
	virtual NR_ILibrary * GetLibraryA(const char * pszLibraryPath) = 0;
};
