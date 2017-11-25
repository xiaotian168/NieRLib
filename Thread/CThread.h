
#pragma once

#include "../NieRLibConfig.h"

class NIER_API CThread
{
public:

	static const unsigned int MaxWaitTimeOut = (unsigned int)0xFFFFFFFF;

	class CThreadContent
	{
	private:

		virtual void dummy(void) = 0;
	};

public:

	CThread();

	virtual ~CThread();

public:

	bool CreateThread(void);

	bool TerminateThread(void);

	bool PauseThread(void);

	bool ResumeThread(void);

	bool Wait(const unsigned int uTimeOut);

public:

	virtual void Run(void) = 0;

private:

	CThreadContent * m_pThreadContent{ 0 };
};
