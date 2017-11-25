
#pragma once

#include "../Base/IRefCount.h"

class IMemoryAllocator;

/**
** @brief 字符串转换接口
*/
class IStringConverter : public IRefCount
{
public:

	/**
	** @brief 设置内存分配器
	*/
	virtual void SetMemoryAllocator(IMemoryAllocator * pAllocator) = 0;

	/**
	** @brief 获取内存分配器
	** @remark
	**
	** 用完之后记得 Release()
	*/
	virtual IMemoryAllocator * GetMemoryAllocator(void) const = 0;

	/**
	** @brief 将 Unicode 字符串转换为 MultiByte 字符串
	*/
	virtual bool UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) = 0;

	/**
	** @brief 将 Unicode 字符串转换为 UTF-8 MultiByte 字符串
	*/
	virtual bool UnicodeToUTF8MultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) = 0;

	/**
	** @brief 将 MultiByte 字符串转换为 Unicode 字符串
	*/
	virtual bool MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) = 0;

	/**
	** @brief 将 MultiByte 字符串转换为 UTF-8 Unicode 字符串
	*/
	virtual bool MultiByteToUTF8Unicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) = 0;

	/**
	** @brief 释放 Unicode 字符串
	*/
	virtual void FreeUnicodeString(const wchar_t * pszUnicodeString) = 0;

	/**
	** @brief 释放 MultiByte 字符串
	*/
	virtual void FreeMultiByteString(const char * pszMultiByteString) = 0;
};
