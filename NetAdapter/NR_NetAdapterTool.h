
#pragma once

#include "../NieRLibConfig.h"

/**
** @brief �Ͽ�������������������
*/
NR_CAPI bool NR_DisconnectAllNetAdapter(void);

/**
** @brief ������������������
*/
NR_CAPI bool NR_ConnectAllNetAdapter(void);

/**
** @brief �ж��Ƿ�����Ѿ��������ӵ�����������
*/
NR_CAPI bool NR_IsConnectedNetAdapterExist(void);
