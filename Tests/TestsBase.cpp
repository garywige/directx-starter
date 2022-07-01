#include "TestsBase.h"
#include <iostream>

void TestsBase::RunAll(const char* className)
{
	std::cout << className << "\r\n";

	for (int i = 0; i < pAdapters->size(); i++)
	{
		runTest(pTitles->at(i), pAdapters->at(i));
	}
}

void TestsBase::Assert(bool bExpression)
{
	std::cout << "\t" << (bExpression ? "PASSED" : "FAILED") << "\t";
}

void TestsBase::RegisterTest(const char* testName, TestAdapter adapter)
{
	pTitles->push_back(testName);
	pAdapters->push_back(adapter);
}

void TestsBase::runTest(const char* title, TestAdapter testAdapter)
{
	beforeEach();
	(*testAdapter)(this);
	printTitle(title);
	afterEach();
}

void TestsBase::printTitle(const char* title)
{
	std::cout << title << "\r\n";
}

void TestsBase::beforeEach()
{}

void TestsBase::afterEach()
{}