#pragma once
#include "TestsBase.h"
#include "..\WindowManagement\GameLoop.h"
#include "FakeMessageHandler.h"

class GameLoopTests : public TestsBase
{
public:
	GameLoopTests();
	~GameLoopTests();

	GameLoop* pSut;

	static void testHandleCalled(TestsBase* tests);
	static void testLoopLoops(TestsBase* tests);

protected:

	void beforeEach() override;
	void afterEach() override;

	FakeMessageHandler* pMessageHandler;
	MSG msg;
};