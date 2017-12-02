
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �߳�
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
	** @brief �����߳�
	*/
	bool CreateThread(void);

	/**
	** @brief ��ֹ�߳�
	*/
	bool TerminateThread(void);

	/**
	** @brief ��ͣ�߳�
	*/
	bool PauseThread(void);

	/**
	** @brief �ָ��߳�
	*/
	bool ResumeThread(void);

	/**
	** @brief �ȴ��߳�
	*/
	bool Wait(const unsigned int uTimeOut);

public:

	virtual void Run(void) = 0;

private:

	CThreadContent * m_pThreadContent{ 0 };
};
