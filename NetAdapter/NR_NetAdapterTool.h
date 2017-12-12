
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 断开所有网络适配器连接
*/
NR_CAPI bool NR_DisconnectAllNetAdapter(void);

/**
** @brief 连接所有网络适配器
*/
NR_CAPI bool NR_ConnectAllNetAdapter(void);

/**
** @brief 判断是否存在已经建立连接的网络适配器
*/
NR_CAPI bool NR_IsConnectedNetAdapterExist(void);
