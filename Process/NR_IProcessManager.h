
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IProcess;

/**
** @brief ���̹���ӿ�
*/
class NR_IProcessManager : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ��ǰ�����б�
	*/
	virtual bool QueryProcessList(std::list<NR_IProcess *> & ProcessList) = 0;

	/**
	** @brief ��ȡ��ǰ����
	*/
	virtual NR_IProcess * GetCurrentProcess(void) = 0;
};
