
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ��ӿ�
*/
class NR_ILibrary : public NR_IRefCount
{
public:

	/**
	** @brief ��������
	*/
	virtual void * ExportSymbolW(const wchar_t * pszSymbolName) = 0;
	virtual void * ExportSymbolA(const char * pszSymbolName) = 0;
};
