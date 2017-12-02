
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IShortcut;

/**
** @brief ��ݷ�ʽ�������ӿ�
*/
class NR_IShortcutManager : public NR_IRefCount
{
public:

	/**
	** @brief ����ָ��·���µ����п�ݷ�ʽ
	*/
	virtual bool SearchShortcutW(const wchar_t * pszSearchDirectory, std::list<NR_IShortcut *> & ShortcutList) = 0;
};
