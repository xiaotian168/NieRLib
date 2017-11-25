
#pragma once

#include "../Base/IRefCount.h"

class IWorkProgress;

/**
** @brief �鵵������ӿ�
*/
class IArchiverUnpacker : public IRefCount
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
	virtual bool Decompress(IWorkProgress * pWorkProgress) = 0;
};
