
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IThread;

/**
** @brief �̹߳������ӿ�
*/
class NR_IThreadManager : public NR_IRefCount
{
public:

	/**
	** @brief ��ȡ�������߳̽ӿ�
	*/
	virtual NR_IThread * GetCurrentThread(void) = 0;
};
