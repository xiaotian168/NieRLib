
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief �߳̽ӿ�
*/
class IThread : public IRefCount
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
