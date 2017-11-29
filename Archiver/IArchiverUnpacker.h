
#pragma once

#include "../Base/IRefCount.h"

class IWorkProgress;
class IArchiverItem;

/**
** @brief 归档解包器接口
*/
class IArchiverUnpacker : public IRefCount
{
public:

	/**
	** @brief 设置归档文件解包路径
	** @return true 表示成功，false 表示失败
	*/
	virtual bool SetDecompressPathW(const wchar_t * pszDecompressPath) = 0;

	/**
	** @brief 解开归档文件
	** @param pWorkProgress 解开进度通知接口
	** @return true 表示成功，false 表示失败
	*/
	virtual bool Decompress(IWorkProgress * pWorkProgress) = 0;

	/**
	** @brief 解包指定元素
	*/
	virtual bool DecompressItem(IArchiverItem * pItem) = 0;
};
