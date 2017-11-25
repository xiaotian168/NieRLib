
#pragma once

#include "IFile.h"
#include <stdio.h>

class CWin32File : public IFile
{
public:

	static CWin32File * MakeW(const wchar_t * pszFilePath, const wchar_t * pszMode);

protected:

	CWin32File(const wchar_t * pszFilePath, const wchar_t * pszMode);

	~CWin32File();

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
