
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 网络适配器接口
*/
class NR_INetAdapter : public NR_IRefCount
{
public:

	/**
	** @brief 获取适配器名称
	*/
	virtual bool GetAdapterNameW(wchar_t * pszName, const unsigned int uSize) = 0;

	/**
	** @brief 重命名适配器名称
	*/
	virtual bool RenameAdapterNameW(const wchar_t * pszName) = 0;

	/**
	** @brief 断开适配器连接
	*/
	virtual bool Disconnect(void) = 0;

	/**
	** @brief 建立适配器连接
	*/
	virtual bool Connect(void) = 0;

	/**
	** @brief 删除适配器
	*/
	virtual bool Delete(void) = 0;

	/**
	** @brief 是否已连接
	*/
	virtual bool IsConnected(void) = 0;

	/**
	** @brief 是否已断开连接
	*/
	virtual bool IsDisconnected(void) = 0;

	/**
	** @brief 是否连接中
	*/
	virtual bool IsConnecting(void) = 0;

	/**
	** @brief 是否断开连接中
	*/
	virtual bool IsDisconnecting(void) = 0;
};
