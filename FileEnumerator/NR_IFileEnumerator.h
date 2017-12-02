
#pragma once

#include "../Base/NR_IRefCount.h"

class NR_IFileEnumResult;

/**
** @brief �ļ�ö�����ӿ�
*/
class NR_IFileEnumerator : public NR_IRefCount
{
public:

	/**
	** @brief ö��ָ��Ŀ¼��ӵ��ָ����׺���������ļ�
	** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
	** @param pszFileExt Ҫ����ö�ٵ��ļ���׺��
	** @param bEnumSubDir �Ƿ�ö����Ŀ¼
	** @param ResultList ����ö�ٽ��
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) = 0;

	/**
	** @brief ö��ָ��Ŀ¼�µ������ļ�Ŀ¼
	** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
	** @param bEnumSubDir �Ƿ�ö����Ŀ¼
	** @param ResultList ����ö�ٽ��
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	virtual bool EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList) = 0;
};
