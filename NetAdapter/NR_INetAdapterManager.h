
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_INetAdapter;

/**
** @brief �����������������ӿ�
*/
class NR_INetAdapterManager : public NR_IRefCount
{
public:
	
	/**
	** @brief ��ѯ�������б�
	*/
	virtual bool QueryAdapterList(std::list<NR_INetAdapter *> & AdapterList) = 0;
};
