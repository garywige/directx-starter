#pragma once
#include <Windows.h>

class IMessageHandler
{
public:
	virtual void Handle(MSG* pMsg) = 0;
};