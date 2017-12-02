
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 文件接口
*/
class NR_IFile : public NR_IRefCount
{
public:

	/**
	** @brief 关闭文件
	*/
	virtual bool Close(void) = 0;

	/**
	** @brief 移动文件指针到指定位置
	*/
	virtual bool SeekTo(const long nPos) = 0;

	/**
	** @brief 移动文件指针到文件头部
	*/
	virtual bool SeekToBegin(void) = 0;

	/**
	** @brief 移动文件指针到文件尾部
	*/
	virtual bool SeekToEnd(void) = 0;

	/**
	** @brief 偏移文件指针指定距离
	*/
	virtual bool SeekOffset(const long nOffset) = 0;

	/**
	** @brief 获取当前文件指针位置
	*/
	virtual long Tell(void) = 0;

	/**
	** @brief 从文件读取数据
	*/
	virtual bool Read(void * pBuffer, const unsigned int uBytes) = 0;

	/**
	** @brief 将数据写入到文件
	*/
	virtual bool Write(const void * pBuffer, const unsigned int uBytes) = 0;
};
