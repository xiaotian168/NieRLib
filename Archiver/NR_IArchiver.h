
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IArchiverItemEnumerator;

/**
** @brief �鵵�ӿ�
*/
class NR_IArchiver : public NR_IRefCount
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
	virtual NR_IArchiverItemEnumerator * GetItemEnumerator(void) = 0;
};
