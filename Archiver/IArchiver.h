
#pragma once

#include "../Base/IRefCount.h"

class IArchiverItemEnumerator;

/**
** @brief �鵵�ӿ�
*/
class IArchiver : public IRefCount
{
public:

	/**
	** @brief �򿪹鵵�ļ�
	** @param pszArchiverPath �鵵�ļ�·��
	** @param pszPassword �鵵�ļ�����
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool OpenArchiverW(const wchar_t * pszArchiverPath, const char * pszPassword) = 0;

	/**
	** @brief �رչ鵵�ļ�
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool CloseArchiver(void) = 0;

	/**
	** @brief ��ȡԪ��ö����
	** @return Ԫ��ö����
	*/
	virtual IArchiverItemEnumerator * GetItemEnumerator(void) = 0;
};
