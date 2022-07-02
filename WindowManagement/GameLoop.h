#pragma once
#include "IMessageHandler.h"

class GameLoop
{
public:
	GameLoop(IMessageHandler* messageHandler, MSG* msg);

	void Loop();

protected:
	IMessageHandler* pMessageHandler;
	MSG* pMsg;
};