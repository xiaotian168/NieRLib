
#pragma once

#include "../NieRLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define NR_EnumAllFile NR_EnumAllFileW
#	define NR_EnumAllDirectory NR_EnumAllDirectoryW
#else
#	define NR_EnumAllFile NR_EnumAllFileA
#	define NR_EnumAllDirectory NR_EnumAllDirectoryA
#endif

class NR_IFileEnumResult;

/**
** @brief ö��ָ��Ŀ¼��ӵ��ָ����׺���������ļ�
** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
** @param pszFileExt Ҫ����ö�ٵ��ļ���׺��
** @param bEnumSubDir �Ƿ�ö����Ŀ¼
** @param ResultList ����ö�ٽ��
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_EnumAllFileW(const wchar_t * pszDirectory, const wchar_t * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
NR_CAPI bool NR_EnumAllFileA(const char * pszDirectory, const char * pszFileExt, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);

/**
** @brief ö��ָ��Ŀ¼�µ������ļ�Ŀ¼
** @param pszDirectory Ҫ����ö�ٵ�Ŀ¼
** @param bEnumSubDir �Ƿ�ö����Ŀ¼
** @param ResultList ����ö�ٽ��
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
NR_CAPI bool NR_EnumAllDirectoryW(const wchar_t * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
NR_CAPI bool NR_EnumAllDirectoryA(const char * pszDirectory, const bool bEnumSubDir, std::list<NR_IFileEnumResult *> & ResultList);
