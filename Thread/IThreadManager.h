
#pragma once

#include "../Base/IRefCount.h"

class IThread;

/**
** @brief �̹߳������ӿ�
*/
class IThreadManager : public IRefCount
{
public:

	/**
	** @brief ��ȡ�������߳̽ӿ�
	*/
	virtual IThread * GetCurrentThread(void) = 0;
};
