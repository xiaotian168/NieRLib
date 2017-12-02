
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IWorkProgress;
class NR_IArchiverItem;

/**
** @brief �鵵������ӿ�
*/
class NR_IArchiverUnpacker : public NR_IRefCount
{
public:

	/**
	** @brief ���ù鵵�ļ����·��
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool SetDecompressPathW(const wchar_t * pszDecompressPath) = 0;

	/**
	** @brief �⿪�鵵�ļ�
	** @param pWorkProgress �⿪����֪ͨ�ӿ�
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool Decompress(NR_IWorkProgress * pWorkProgress) = 0;

	/**
	** @brief ���ָ��Ԫ��
	*/
	virtual bool DecompressItem(NR_IArchiverItem * pItem) = 0;
};
