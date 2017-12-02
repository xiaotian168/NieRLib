
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief �ļ�·���ӿ�
*/
class NR_IFilePath : public NR_IRefCount
{
public:

	/**
	** @brief ��·���зָ��Ŀ¼�ɷ�
	*/
	virtual bool SplitDirectoryW(const wchar_t * pszPathToSplit, wchar_t * pszDirectory, const unsigned int uSize) = 0;

	/**
	** @brief ��·���зָ���ļ����ɷ�
	*/
	virtual bool SplitFileTitleW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) = 0;

	/**
	** @brief ��·���зָ���ļ����ɷ֣��������ļ���չ��
	*/
	virtual bool SplitFileTitleWithNoExeW(const wchar_t * pszPathToSplit, wchar_t * pszFileTitle, const unsigned int uSize) = 0;

	/**
	** @brief ��·���зָ���ļ���չ��
	*/
	virtual bool SplitFileExtW(const wchar_t * pszPathToSplit, wchar_t * pszFileExt, const unsigned int uSize) = 0;

	/**
	** @brief �Զ���·��ĩβ���б���ַ�
	*/
	virtual bool AppendBackslashW(wchar_t * pszPath, const unsigned int uSize) = 0;
};
