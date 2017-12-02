
#pragma once

#include "../Base/NR_IRefCount.h"

/**
** @brief 日志接口
*/
class NR_ILog : public NR_IRefCount
{
public:

	/**
	** @brief 日志信息级别
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
	** @brief 设置日志信息过滤级别
	*/
	virtual bool SetFilterLogLevel(const NR_LogLevel Level) = 0;

	/**
	** @brief 获取日志信息过滤级别
	*/
	virtual NR_LogLevel GetFilterLogLevel(void) const = 0;

	/**
	** @brief 记录日志信息
	*/
	virtual bool LogMsgW(const NR_LogLevel Level, const wchar_t * pszMsg) = 0;
	virtual bool LogMsgA(const NR_LogLevel Level, const char * pszMsg) = 0;

	/**
	** @brief 记录格式化日志信息
	*/
	virtual bool LogFormatMsgW(const NR_LogLevel Level, const wchar_t * pszFmt, ...) = 0;
	virtual bool LogFormatMsgA(const NR_LogLevel Level, const char * pszFmt, ...) = 0;
};
