
#pragma once

#include "../Base/IRefCount.h"
#include <list>

class IShortcut;

/**
** @brief 快捷方式管理器接口
*/
class IShortcutManager : public IRefCount
{
public:

	/**
	** @brief 搜索指定路径下的所有快捷方式
	*/
	virtual bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<IShortcut *> & ShortcutList) = 0;
};
