
#pragma once

#include "../Base/IRefCount.h"
#include <list>

class INetAdapter;

/**
** @brief �����������������ӿ�
*/
class INetAdapterManager : public IRefCount
{
public:
	
	/**
	** @brief ��ѯ�������б�
	*/
	virtual bool QueryAdapterList(std::list<INetAdapter *> & AdapterList) = 0;
};
