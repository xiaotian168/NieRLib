
#pragma once

enum NR_WindowEventType
{
	eWindowEvent_Unknown = 0,
	eWindowEvent_MouseMove,
	eWindowEvent_MouseWheel,
	eWindowEvent_KeyDown,
	eWindowEvent_KeyUp,
};

enum NR_SystemEventType
{
	eSystemEvent_Unknown,
};

class NR_CWindowEvent
{
public:

	NR_WindowEventType EventType{ eWindowEvent_Unknown };
	long nCursorX{ 0 };
	long nCursorY{ 0 };
	bool bWheelForward{ false };
};

class NR_CSystemEvent
{
public:

	NR_SystemEventType EventType{ eSystemEvent_Unknown };
};
