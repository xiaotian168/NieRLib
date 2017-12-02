
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IShortcut;

/**
** @brief 快捷方式管理器接口
*/
class NR_IShortcutManager : public NR_IRefCount
{
public:

	/**
	** @brief 搜索指定路径下的所有快捷方式
	*/
	virtual bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<NR_IShortcut *> & ShortcutList) = 0;
};
