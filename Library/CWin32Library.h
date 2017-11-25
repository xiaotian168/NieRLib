
#pragma once

#include "ILibrary.h"
#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

class CWin32Library : public ILibrary
{
public:

	static CWin32Library * Make(const HMODULE hModule);

protected:

	CWin32Library(const HMODULE hModule);

	~CWin32Library();

public:

	void * ExportSymbolW(const wchar_t * pszSymbolName) override;

	void * ExportSymbolA(const char * pszSymbolName) override;

private:

	HMODULE m_hModule{ 0 };
};

#endif
