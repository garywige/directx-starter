#pragma once
#include "..\WindowManagement\IMessageHandler.h"

class FakeMessageHandler : public IMessageHandler
{
public:
	FakeMessageHandler();
	void Handle(MSG* pMsg) override;
	bool getHandleCalled();
	int getCallCount();

private:
	bool isHandleCalled;
	int callCount;
};