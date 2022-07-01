#pragma once
#include <Windows.h>

class MessageHandler
{
public:
	MessageHandler();
	void Handle(MSG* pMsg);
};