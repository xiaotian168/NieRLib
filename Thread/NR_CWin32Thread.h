
#pragma once

#include "NR_IThread.h"

#if defined NR_PLATFORM_WIN32

class NR_CWin32Thread : public NR_IThread
{
public:

	static NR_CWin32Thread * Make(const HANDLE hThread);

protected:

	NR_CWin32Thread(const HANDLE hThread);

	~NR_CWin32Thread();

public:

	bool GetThreadID(IDType & ID) override;

	bool ShutdownThread(const unsigned int uExitCode) override;

private:

	HANDLE m_hThread{ 0 };
};

#endif
