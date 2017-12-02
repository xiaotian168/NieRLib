
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWorkProgress;
class NR_IArchiverItem;

/**
** @brief 归档解包器接口
*/
class NR_IArchiverUnpacker : public NR_IRefCount
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
	virtual bool Decompress(NR_IWorkProgress * pWorkProgress) = 0;

	/**
	** @brief 解包指定元素
	*/
	virtual bool DecompressItem(NR_IArchiverItem * pItem) = 0;
};
