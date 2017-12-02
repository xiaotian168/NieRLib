
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �ļ�ö�ٽ���ӿ�
*/
class NR_IFileEnumResult : public NR_IRefCount
{
public:

	/**
	** @brief �ж��Ƿ�Ŀ¼
	*/
	virtual bool IsDirectory(void) const = 0;

	/**
	** @brief ��ȡ��׺��
	*/
	virtual bool GetFileExtW(wchar_t * pszExt, const unsigned int uSize) = 0;

	/**
	** @brief ��ȡ·��
	*/
	virtual bool GetResultPathW(wchar_t * pszPath, const unsigned int uSize) const = 0;
};
