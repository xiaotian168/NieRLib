
#define _NIER_API

#include "StringConverterTool.h"
#include "IStringConverter.h"
#include "StringConverterFactory.h"
#include "../MemoryAllocator/IMemoryAllocator.h"
#include "../MemoryAllocator/MemoryAllocatorFactory.h"

class CStringConverterHelper
{
public:

	inline CStringConverterHelper()
	{
		auto pMemAllocator = MakeMemoryAllocatorByOSPlatform();
		if (pMemAllocator)
		{
			pStringConverter = MakeStringConverterByOSPlatform();
			if (pStringConverter)
			{
				pStringConverter->SetMemoryAllocator(pMemAllocator);
			}

			SAFE_RELEASE(pMemAllocator);
		}
	}

	inline ~CStringConverterHelper()
	{
		SAFE_RELEASE(pStringConverter);
	}

public:

	static IStringConverter * pStringConverter;
};

IStringConverter * CStringConverterHelper::pStringConverter = 0;
CStringConverterHelper StringConverterHelper;

char * Unicode2MultiByte(const wchar_t * pszUnicodeString)
{
	char * pszMultiByteString = 0;

	if (pszUnicodeString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->UnicodeToMultiByte(pszUnicodeString, &pszMultiByteString);
	}

	return pszMultiByteString;
}

char * Unicode2UTF8MultiByte(const wchar_t * pszUnicodeString)
{
	char * pszMultiByteString = 0;

	if (pszUnicodeString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->UnicodeToUTF8MultiByte(pszUnicodeString, &pszMultiByteString);
	}

	return pszMultiByteString;
}

wchar_t * MultiByte2Unicode(const char * pszMultiByteString)
{
	wchar_t * pszUnicodeString = 0;

	if (pszMultiByteString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->MultiByteToUnicode(pszMultiByteString, &pszUnicodeString);
	}

	return pszUnicodeString;
}

wchar_t * MultiByte2UTF8Unicode(const char * pszMultiByteString)
{
	wchar_t * pszUnicodeString = 0;

	if (pszMultiByteString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->MultiByteToUTF8Unicode(pszMultiByteString, &pszUnicodeString);
	}

	return pszUnicodeString;
}

void FreeUnicodeString(const wchar_t * pszUnicodeString)
{
	if (pszUnicodeString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->FreeUnicodeString(pszUnicodeString);
	}
}

void FreeMultiByteString(const char * pszMultiByteString)
{
	if (pszMultiByteString && CStringConverterHelper::pStringConverter)
	{
		CStringConverterHelper::pStringConverter->FreeMultiByteString(pszMultiByteString);
	}
}
