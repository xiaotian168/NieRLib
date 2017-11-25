
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ��ӿ�
*/
class ILibrary : public IRefCount
{
public:

	/**
	** @brief ��������
	*/
	virtual void * ExportSymbolW(const wchar_t * pszSymbolName) = 0;
	virtual void * ExportSymbolA(const char * pszSymbolName) = 0;
};
