
#pragma once

enum NR_WindowEventType
{
	eEvent_Unknown = 0,
	eEvent_MouseMove,
	eEvent_MouseWheel,
	eEvent_KeyDown,
	eEvent_KeyUp,
};

class NR_CWindowEvent
{
public:

	NR_WindowEventType EventType{ eEvent_Unknown };
	long nCursorX{ 0 };
	long nCursorY{ 0 };
	bool bWheelForward{ false };
};

class NR_CSystemEvent
{

};
