
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief ��־�ӿ�
*/
class ILog : public IRefCount
{
public:

	/**
	** @brief ��־��Ϣ����
	*/
	enum emLogLevel
	{
		eLogLevel_All,
		eLogLevel_Warning,
		eLogLevel_Error,
		eLogLevel_Slient,
	};

public:

	/**
	** @brief ������־��Ϣ���˼���
	*/
	virtual bool SetFilterLogLevel(const emLogLevel Level) = 0;

	/**
	** @brief ��ȡ��־��Ϣ���˼���
	*/
	virtual emLogLevel GetFilterLogLevel(void) const = 0;

	/**
	** @brief ��¼��־��Ϣ
	*/
	virtual bool LogMsgW(const emLogLevel Level, const wchar_t * pszMsg) = 0;
	virtual bool LogMsgA(const emLogLevel Level, const char * pszMsg) = 0;

	/**
	** @brief ��¼��ʽ����־��Ϣ
	*/
	virtual bool LogFormatMsgW(const emLogLevel Level, const wchar_t * pszFmt, ...) = 0;
	virtual bool LogFormatMsgA(const emLogLevel Level, const char * pszFmt, ...) = 0;
};
