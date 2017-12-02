
#pragma once

#include "NR_IFile.h"

#if defined NIER_PLATFORM_WIN32

class NR_CWin32File : public NR_IFile
{
public:

	static NR_CWin32File * MakeW(const wchar_t * pszFilePath, const wchar_t * pszMode);

protected:

	NR_CWin32File(const wchar_t * pszFilePath, const wchar_t * pszMode);

	~NR_CWin32File();

public:

	bool Close(void) override;

	bool SeekTo(const long nPos) override;

	bool SeekToBegin(void) override;

	bool SeekToEnd(void) override;

	bool SeekOffset(const long nOffset) override;

	long Tell(void) override;

	bool Read(void * pBuffer, const unsigned int uBytes) override;

	bool Write(const void * pBuffer, const unsigned int uBytes) override;

private:

	FILE * m_pFile{ 0 };
};

#endif
