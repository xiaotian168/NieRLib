
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IMemoryAllocator;

/**
** @brief �ַ���ת���ӿ�
*/
class NR_IStringConverter : public NR_IRefCount
{
public:

	/**
	** @brief �����ڴ������
	*/
	virtual void SetMemoryAllocator(NR_IMemoryAllocator * pAllocator) = 0;

	/**
	** @brief ��ȡ�ڴ������
	** @remark
	**
	** ����֮��ǵ� Release()
	*/
	virtual NR_IMemoryAllocator * GetMemoryAllocator(void) const = 0;

	/**
	** @brief �� Unicode �ַ���ת��Ϊ MultiByte �ַ���
	*/
	virtual bool UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) = 0;

	/**
	** @brief �� Unicode �ַ���ת��Ϊ UTF-8 MultiByte �ַ���
	*/
	virtual bool UnicodeToUTF8MultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) = 0;

	/**
	** @brief �� MultiByte �ַ���ת��Ϊ Unicode �ַ���
	*/
	virtual bool MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) = 0;

	/**
	** @brief �� MultiByte �ַ���ת��Ϊ UTF-8 Unicode �ַ���
	*/
	virtual bool MultiByteToUTF8Unicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) = 0;

	/**
	** @brief �ͷ� Unicode �ַ���
	*/
	virtual void FreeUnicodeString(const wchar_t * pszUnicodeString) = 0;

	/**
	** @brief �ͷ� MultiByte �ַ���
	*/
	virtual void FreeMultiByteString(const char * pszMultiByteString) = 0;
};
