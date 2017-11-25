
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ��ݷ�ʽ�ӿ�
*/
class IShortcut : public IRefCount
{
public:

	/**
	** @brief ��ȡ��ݷ�ʽĿ��·��
	*/
	virtual bool GetTargetPathW(wchar_t * pszTargetPath, const unsigned int uSize) = 0;

	/**
	** @brief ��ȡ��ݷ�ʽ·��
	*/
	virtual bool GetPathW(wchar_t * pszPath, const unsigned int uSize) = 0;

	/**
	** @brief ɾ����ݷ�ʽ
	*/
	virtual bool Delete(void) = 0;
};
