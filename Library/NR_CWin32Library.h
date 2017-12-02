
#pragma once

#include "NR_ILibrary.h"
#include "../NieRLibConfig.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32Library : public NR_ILibrary
{
public:

	static NR_CWin32Library * Make(const HMODULE hModule);

protected:

	NR_CWin32Library(const HMODULE hModule);

	~NR_CWin32Library();

public:

	void * ExportSymbolW(const wchar_t * pszSymbolName) override;

	void * ExportSymbolA(const char * pszSymbolName) override;

private:

	HMODULE m_hModule{ 0 };
};

#endif
