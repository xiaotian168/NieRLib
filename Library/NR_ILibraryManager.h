
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_ILibrary;

/**
** @brief 库接管理器口
*/
class NR_ILibraryManager : public NR_IRefCount
{
public:

	/**
	** @brief 加载库
	*/
	virtual NR_ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) = 0;
	virtual NR_ILibrary * GetLibraryA(const char * pszLibraryPath) = 0;
};
