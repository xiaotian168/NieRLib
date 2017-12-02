
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �߳̽ӿ�
*/
class NR_IThread : public NR_IRefCount
{
public:

	typedef unsigned long IDType;

public:

	/**
	** @brief ��ȡ�߳� ID
	*/
	virtual bool GetThreadID(IDType & ID) = 0;

	/**
	** @brief �ر��߳�
	*/
	virtual bool ShutdownThread(const unsigned int uExitCode) = 0;
};
