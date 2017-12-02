
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IArchiverItemEnumerator;

/**
** @brief 归档接口
*/
class NR_IArchiver : public NR_IRefCount
{
public:

	/**
	** @brief 打开归档文件
	** @param pszArchiverPath 归档文件路径
	** @param pszPassword 归档文件密码
	** @return true 表示成功，false 表示失败
	*/
	virtual bool OpenArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword) = 0;

	/**
	** @brief 关闭归档文件
	** @return true 表示成功，false 表示失败
	*/
	virtual bool CloseArchiver(void) = 0;

	/**
	** @brief 获取元素枚举器
	** @return 元素枚举器
	*/
	virtual NR_IArchiverItemEnumerator * GetItemEnumerator(void) = 0;
};
