
#pragma once

#include "../Base/IRefCount.h"
#include <list>

class IShortcut;

/**
** @brief ��ݷ�ʽ�������ӿ�
*/
class IShortcutManager : public IRefCount
{
public:

	/**
	** @brief ����ָ��·���µ����п�ݷ�ʽ
	*/
	virtual bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<IShortcut *> & ShortcutList) = 0;
};
