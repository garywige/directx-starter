#include "GameLoopTests.h"
#include "..\WindowManagement\GameLoop.h"
#include "FakeMessageHandler.h"

GameLoopTests::GameLoopTests()
{
	pSut = 0;
	pMessageHandler = 0;

	pAdapters = new std::vector<TestAdapter>();
	pTitles = new std::vector<const char*>();

	RegisterTest("MessageHandler.Handle() called", testHandleCalled);
	RegisterTest("Loop() loops", testLoopLoops);
}

GameLoopTests::~GameLoopTests()
{
	if (pSut)
	{
		delete pSut;
		pSut = 0;
	}

	if (pMessageHandler)
	{
		delete pMessageHandler;
		pMessageHandler = 0;
	}

	delete pAdapters;
	delete pTitles;
}

void GameLoopTests::beforeEach()
{
	pMessageHandler = new FakeMessageHandler();
	pSut = new GameLoop(pMessageHandler, &msg);
	msg = {};
}

void GameLoopTests::afterEach()
{
	delete pSut;
	delete pMessageHandler;
	pSut = 0;
	pMessageHandler = 0;
}

void GameLoopTests::testHandleCalled(TestsBase* tests)
{
	GameLoopTests* pTests = (GameLoopTests*)tests;
	pTests->pSut->Loop();
	pTests->Assert(pTests->pMessageHandler->getHandleCalled());
}

void GameLoopTests::testLoopLoops(TestsBase* tests)
{
	GameLoopTests* pTests = (GameLoopTests*)tests;
	pTests->pSut->Loop();
	pTests->Assert(pTests->pMessageHandler->getCallCount() > 1);
}