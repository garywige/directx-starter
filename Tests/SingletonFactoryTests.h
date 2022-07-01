#pragma once
#include <string>
#include "TestsBase.h"
#include "..\Factory\SingletonFactory.h"

class SingletonFactoryTests : public TestsBase
{
public:
	SingletonFactoryTests();
	~SingletonFactoryTests();

	static void testCreateIsNotNull(TestsBase* tests);
	static void testCreateReturnsSameInstance(TestsBase* tests);

	SingletonFactory<int>* pSut;

protected:

	void beforeEach() override;
	void afterEach() override;
};