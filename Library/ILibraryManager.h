
#pragma once

#include "../Base/IRefCount.h"

class ILibrary;

/**
** @brief 库接管理器口
*/
class ILibraryManager : public IRefCount
{
public:

	/**
	** @brief 加载库
	*/
	virtual ILibrary * GetLibraryW(const wchar_t * pszLibraryPath) = 0;
	virtual ILibrary * GetLibraryA(const char * pszLibraryPath) = 0;
};
