
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief 断开所有网络适配器连接
*/
NIER_CAPI bool DisconnectAllNetAdapter(void);

/**
** @brief 连接所有网络适配器
*/
NIER_CAPI bool ConnectAllNetAdapter(void);
