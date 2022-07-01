#pragma once
#include "IMessageHandler.h"

class MessageHandler : public IMessageHandler
{
public:
	MessageHandler();
	void Handle(MSG* pMsg);
};