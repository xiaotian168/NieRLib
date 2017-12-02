
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 线程
*/
class NIER_API NR_CThread
{
public:

	static const unsigned int MaxWaitTimeOut = (unsigned int)0xFFFFFFFF;

	class CThreadContent
	{
	private:

		virtual void dummy(void) = 0;
	};

public:

	NR_CThread();

	virtual ~NR_CThread();

public:

	/**
	** @brief 创建线程
	*/
	bool CreateThread(void);

	/**
	** @brief 终止线程
	*/
	bool TerminateThread(void);

	/**
	** @brief 暂停线程
	*/
	bool PauseThread(void);

	/**
	** @brief 恢复线程
	*/
	bool ResumeThread(void);

	/**
	** @brief 等待线程
	*/
	bool Wait(const unsigned int uTimeOut);

public:

	virtual void Run(void) = 0;

private:

	CThreadContent * m_pThreadContent{ 0 };
};
