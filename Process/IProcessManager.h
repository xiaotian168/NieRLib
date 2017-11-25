
#pragma once

#include "../Base/IRefCount.h"
#include <list>

class IProcess;

/**
** @brief ���̹����ӿ�
*/
class IProcessManager : public IRefCount
{
public:

	/**
	** @brief ��ȡ��ǰ�����б�
	*/
	virtual bool QueryProcessList(std::list<IProcess *> & ProcessList) = 0;
};