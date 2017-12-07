
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWindow;
class NR_IApplicationStartupParam;
class NR_IApplicationEventReceiver;

/**
** @brief Ӧ�ó���ӿ�
*/
class NR_IApplication : public NR_IRefCount
{
public:

	/**
	** @brief ��ʼ��Ӧ�ó���
	*/
	virtual bool Init(NR_IApplicationStartupParam * pStartupParam, NR_IApplicationEventReceiver * pEventReceiver) = 0;

	/**
	** @brief ��ʼ��Ӧ�ó���
	*/
	virtual void Uninit(void) = 0;

	/**
	** @brief ����Ӧ�ó���
	*/
	virtual bool Run(void) = 0;

	/**
	** @brief ��������
	*/
	virtual NR_IWindow * MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight) = 0;
};
