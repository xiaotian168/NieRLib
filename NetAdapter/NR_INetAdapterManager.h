
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_INetAdapter;

/**
** @brief 网络适配器管理器接口
*/
class NR_INetAdapterManager : public NR_IRefCount
{
public:
	
	/**
	** @brief 查询适配器列表
	*/
	virtual bool QueryAdapterList(std::list<NR_INetAdapter *> & AdapterList) = 0;
};
