
#pragma once

#include "IThread.h"

#if defined NIER_PLATFORM_WIN32

class CWin32Thread : public IThread
{
public:

	static CWin32Thread * Make(const HANDLE hThread);

protected:

	CWin32Thread(const HANDLE hThread);

	~CWin32Thread();

public:

	bool GetThreadID(IDType & ID) override;

	bool ShutdownThread(const unsigned int uExitCode) override;

private:

	HANDLE m_hThread{ 0 };
};

#endif
