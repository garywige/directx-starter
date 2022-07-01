#include ".\MessageHandler.h"

MessageHandler::MessageHandler(){}

void MessageHandler::Handle(MSG* pMsg)
{
	while (pMsg->message != WM_QUIT)
	{
		while (PeekMessage(pMsg, NULL, 0, 0, PM_REMOVE) && pMsg->message != WM_QUIT)
		{
			TranslateMessage(pMsg);
			DispatchMessage(pMsg);
		}

		// TODO: game loop
	}
}