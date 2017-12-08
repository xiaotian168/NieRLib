
#define _NR_API

#include "NR_StringConverterTool.h"
#include "NR_IStringConverter.h"
#include "NR_StringConverterFactory.h"
#include "../MemoryAllocator/NR_IMemoryAllocator.h"
#include "../MemoryAllocator/NR_MemoryAllocatorFactory.h"

class NR_CStringConverterHelper
{
public:

	inline NR_CStringConverterHelper()
	{
		auto pMemAllocator = NR_MakeMemoryAllocatorByOSPlatform();
		if (pMemAllocator)
		{
			pStringConverter = MakeStringConverterByOSPlatform();
			if (pStringConverter)
			{
				pStringConverter->SetMemoryAllocator(pMemAllocator);
			}

			NR_SAFE_RELEASE(pMemAllocator);
		}
	}

	inline ~NR_CStringConverterHelper()
	{
		NR_SAFE_RELEASE(pStringConverter);
	}

public:

	static NR_IStringConverter * pStringConverter;
};

NR_IStringConverter * NR_CStringConverterHelper::pStringConverter = 0;
NR_CStringConverterHelper StringConverterHelper;

char * NR_Unicode2MultiByte(const wchar_t * pszUnicodeString)
{
	char * pszMultiByteString = 0;

	if (pszUnicodeString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->UnicodeToMultiByte(pszUnicodeString, &pszMultiByteString);
	}

	return pszMultiByteString;
}

char * NR_Unicode2UTF8MultiByte(const wchar_t * pszUnicodeString)
{
	char * pszMultiByteString = 0;

	if (pszUnicodeString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->UnicodeToUTF8MultiByte(pszUnicodeString, &pszMultiByteString);
	}

	return pszMultiByteString;
}

wchar_t * NR_MultiByte2Unicode(const char * pszMultiByteString)
{
	wchar_t * pszUnicodeString = 0;

	if (pszMultiByteString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->MultiByteToUnicode(pszMultiByteString, &pszUnicodeString);
	}

	return pszUnicodeString;
}

wchar_t * NR_MultiByte2UTF8Unicode(const char * pszMultiByteString)
{
	wchar_t * pszUnicodeString = 0;

	if (pszMultiByteString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->MultiByteToUTF8Unicode(pszMultiByteString, &pszUnicodeString);
	}

	return pszUnicodeString;
}

void NR_FreeUnicodeString(const wchar_t * pszUnicodeString)
{
	if (pszUnicodeString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->FreeUnicodeString(pszUnicodeString);
	}
}

void NR_FreeMultiByteString(const char * pszMultiByteString)
{
	if (pszMultiByteString && NR_CStringConverterHelper::pStringConverter)
	{
		NR_CStringConverterHelper::pStringConverter->FreeMultiByteString(pszMultiByteString);
	}
}
