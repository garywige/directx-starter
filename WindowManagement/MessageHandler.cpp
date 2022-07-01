#include ".\MessageHandler.h"

MessageHandler::MessageHandler(){}

void MessageHandler::Handle(MSG* pMsg)
{
	while (GetMessage(pMsg, NULL, 0, 0) > 0)
	{
		TranslateMessage(pMsg);
		DispatchMessage(pMsg);
	}
}