
#pragma once

#include "NR_IStringConverter.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32StringConverter : public NR_IStringConverter
{
public:

	static const unsigned int UnicodeCharSize = sizeof(wchar_t);
	static const unsigned int MultiByteCharSize = sizeof(char);

	static NR_CWin32StringConverter * Make(void);

protected:

	NR_CWin32StringConverter();

	~NR_CWin32StringConverter();

public:

	void SetMemoryAllocator(NR_IMemoryAllocator * pAllocator) override;

	NR_IMemoryAllocator * GetMemoryAllocator(void) const override;

	bool UnicodeToMultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) override;

	bool UnicodeToUTF8MultiByte(const wchar_t * pszUnicodeString, char ** ppszMultiByteString) override;

	bool MultiByteToUnicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) override;

	bool MultiByteToUTF8Unicode(const char * pszMultiByteString, wchar_t ** ppszUnicodeString) override;

	void FreeUnicodeString(const wchar_t * pszUnicodeString) override;

	void FreeMultiByteString(const char * pszMultiByteString) override;

private:

	NR_IMemoryAllocator * m_pMemAllocator;
};

#endif
