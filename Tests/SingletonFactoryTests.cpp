#include <iostream>
#include "SingletonFactoryTests.h"
#include "TestsBase.h"

SingletonFactoryTests::SingletonFactoryTests()
{
	pSut = 0;
	pAdapters = new std::vector<TestAdapter>();
	pTitles = new std::vector<const char*>();

	RegisterTest("Create is not null", testCreateIsNotNull);
	RegisterTest("Create returns same instance", testCreateReturnsSameInstance);
}

SingletonFactoryTests::~SingletonFactoryTests()
{
	if (pSut)
	{
		delete pSut;
		pSut = 0;
	}

	delete pAdapters;
	delete pTitles;
}

void SingletonFactoryTests::testCreateIsNotNull(TestsBase* tests)
{
	// Act
	int* result = ((SingletonFactoryTests*)tests)->pSut->Create();

	// Assert
	tests->Assert(result != 0);
}

void SingletonFactoryTests::testCreateReturnsSameInstance(TestsBase* tests)
{
	// Act
	int* result1 = ((SingletonFactoryTests*)tests)->pSut->Create();
	int* result2 = ((SingletonFactoryTests*)tests)->pSut->Create();

	// Assert
	tests->Assert(result1 == result2);
}

void SingletonFactoryTests::beforeEach()
{
	pSut = new SingletonFactory<int>();
}

void SingletonFactoryTests::afterEach()
{
	delete pSut;
	pSut = 0;
}