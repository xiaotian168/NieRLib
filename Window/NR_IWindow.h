
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ���ڽӿ�
*/
class NR_IWindow : public NR_IRefCount
{
public:

	/**
	** @brief ���ش���
	*/
	virtual bool Hide(void) = 0;

	/**
	** @brief ��ʾ����
	*/
	virtual bool Show(void) = 0;

	/**
	** @brief ���ô����ı�
	*/
	virtual bool SetTitleW(const wchar_t * pszTitle) = 0;
};
