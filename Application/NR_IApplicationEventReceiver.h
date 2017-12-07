
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWindow;
class NR_CWindowEvent;
class NR_CSystemEvent;

/**
** @brief Ӧ�ó����¼��������ӿ�
*/
class NR_IApplicationEventReceiver : public NR_IRefCount
{
public:

	/**
	** @brief �����¼��ص�����
	*/
	virtual void OnWindowEvent(NR_IWindow * pWindow, NR_CWindowEvent * pEvent) { }

	/**
	** @brief ϵͳ�¼��ص�����
	*/
	virtual void OnSystemEvent(NR_CSystemEvent * pEvent) { }
};
