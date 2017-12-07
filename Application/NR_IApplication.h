
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWindow;
class NR_IApplicationStartupParam;

/**
** @brief Ӧ�ó���ӿ�
*/
class NR_IApplication : public NR_IRefCount
{
public:

	/**
	** @brief ��ʼ��Ӧ�ó���
	*/
	virtual bool InitApplication(NR_IApplicationStartupParam * pStartupParam) = 0;

	/**
	** @brief ��ʼ��Ӧ�ó���
	*/
	virtual void UninitApplication(void) = 0;

	/**
	** @brief ��������
	*/
	virtual NR_IWindow * MakeWindowW(const wchar_t * pszTitle, const int nPosX, const int nPosY, const unsigned int uWidth, const unsigned int uHeight) = 0;
};
