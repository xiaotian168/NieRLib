
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 库接口
*/
class ILibrary : public IRefCount
{
public:

	/**
	** @brief 导出符号
	*/
	virtual void * ExportSymbolW(const wchar_t * pszSymbolName) = 0;
	virtual void * ExportSymbolA(const char * pszSymbolName) = 0;
};
