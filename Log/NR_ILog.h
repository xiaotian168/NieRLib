
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief ��־�ӿ�
*/
class NR_ILog : public NR_IRefCount
{
public:

	/**
	** @brief ��־��Ϣ����
	*/
	enum NR_LogLevel
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
	virtual bool SetFilterLogLevel(const NR_LogLevel Level) = 0;

	/**
	** @brief ��ȡ��־��Ϣ���˼���
	*/
	virtual NR_LogLevel GetFilterLogLevel(void) const = 0;

	/**
	** @brief ��¼��־��Ϣ
	*/
	virtual bool LogMsgW(const NR_LogLevel Level, const wchar_t * pszMsg) = 0;
	virtual bool LogMsgA(const NR_LogLevel Level, const char * pszMsg) = 0;

	/**
	** @brief ��¼��ʽ����־��Ϣ
	*/
	virtual bool LogFormatMsgW(const NR_LogLevel Level, const wchar_t * pszFmt, ...) = 0;
	virtual bool LogFormatMsgA(const NR_LogLevel Level, const char * pszFmt, ...) = 0;
};
