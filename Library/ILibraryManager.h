
#pragma once

#include "../Base/IRefCount.h"

class ILibrary;

/**
** @brief ��ӹ�������
*/
class ILibraryManager : public IRefCount
{
public:

	/**
	** @brief ���ؿ�
	*/
	virtual ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) = 0;
	virtual ILibrary * GetLibraryA(const char * pszLibraryPath) = 0;
};
