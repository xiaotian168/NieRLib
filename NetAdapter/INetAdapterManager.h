
#pragma once

#include "../Base/IRefCount.h"
#include <list>

class INetAdapter;

/**
** @brief 网络适配器管理器接口
*/
class INetAdapterManager : public IRefCount
{
public:
	
	/**
	** @brief 查询适配器列表
	*/
	virtual bool QueryAdapterList(std::list<INetAdapter *> & AdapterList) = 0;
};
