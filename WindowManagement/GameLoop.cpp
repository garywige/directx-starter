#include "GameLoop.h"

GameLoop::GameLoop(IMessageHandler* messageHandler, MSG* msg)
{
	pMessageHandler = messageHandler;
	pMsg = msg;
}

void GameLoop::Loop()
{
	while (pMsg->message != WM_QUIT)
	{
		pMessageHandler->Handle(pMsg);
	}
}

