
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ϵͳĿ¼�����Ϣ�ӿ�
*/
class NR_ISystemDirectoryInfo : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡϵͳ��ʱĿ¼·��
	*/
	virtual bool GetTempDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) = 0;

	/**
	** @brief ��ȡϵͳĿ¼·��
	*/
	virtual bool GetSystemDirectoryW(wchar_t * pszDirectory, const unsigned int uSize) = 0;
};
