#include "FakeMessageHandler.h"

FakeMessageHandler::FakeMessageHandler()
{
	isHandleCalled = false;
	callCount = 0;
}

void FakeMessageHandler::Handle(MSG* pMsg)
{
	isHandleCalled = true;
	if (callCount++ > 0)
		pMsg->message = WM_QUIT;
}

bool FakeMessageHandler::getHandleCalled()
{
	return isHandleCalled;
}

int FakeMessageHandler::getCallCount()
{
	return callCount;
}