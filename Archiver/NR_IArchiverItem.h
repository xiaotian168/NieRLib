
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �鵵�ļ�Ԫ�ؽӿ�
*/
class NR_IArchiverItem : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡԪ������
	*/
	virtual bool GetItemNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief ��ȡԪ���Ƿ�Ŀ¼
	*/
	virtual bool IsItemDirectory(void) = 0;
};
