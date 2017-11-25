
#pragma once

#include "IStringConverter.h"

#if defined NIER_PLATFORM_WIN32

class CWin32StringConverter : public IStringConverter
{
public:

	static const unsigned int UnicodeCharSize = sizeof(wchar_t);
	static const unsigned int MultiByteCharSize = sizeof(char);

	static CWin32StringConverter * Make(void);

protected:

	CWin32StringConverter();

	~CWin32StringConverter();

public:

	void SetMemoryAllocator(IMemoryAllocator * pAllocator) override;

	IMemoryAllocator * GetMemoryAllocator(void) const override;

	bool UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) override;

	bool MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) override;

	void FreeUnicodeString(const wchar_t * pszUnicodeString) override;

	void FreeMultiByteString(const char * pszMultiByteString) override;

private:

	IMemoryAllocator * m_pMemAllocator;
};

#endif
