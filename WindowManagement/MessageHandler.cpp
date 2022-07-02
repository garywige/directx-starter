#include ".\MessageHandler.h"

MessageHandler::MessageHandler(){}

void MessageHandler::Handle(MSG* pMsg)
{
	while (PeekMessage(pMsg, NULL, 0, 0, PM_REMOVE) && pMsg->message != WM_QUIT)
	{
		TranslateMessage(pMsg);
		DispatchMessage(pMsg);
	}
}