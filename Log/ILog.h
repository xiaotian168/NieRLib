
#pragma once

#include "../Base/IRefCount.h"

/**
** @brief 日志接口
*/
class ILog : public IRefCount
{
public:

	/**
	** @brief 日志信息级别
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
	** @brief 设置日志信息过滤级别
	*/
	virtual bool SetFilterLogLevel(const emLogLevel Level) = 0;

	/**
	** @brief 获取日志信息过滤级别
	*/
	virtual emLogLevel GetFilterLogLevel(void) const = 0;

	/**
	** @brief 记录日志信息
	*/
	virtual bool LogMsgW(const emLogLevel Level, const wchar_t * pszMsg) = 0;
	virtual bool LogMsgA(const emLogLevel Level, const char * pszMsg) = 0;

	/**
	** @brief 记录格式化日志信息
	*/
	virtual bool LogFormatMsgW(const emLogLevel Level, const wchar_t * pszFmt, ...) = 0;
	virtual bool LogFormatMsgA(const emLogLevel Level, const char * pszFmt, ...) = 0;
};
