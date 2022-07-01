#pragma once
#include <vector>

class TestsBase;
typedef void (*TestAdapter)(TestsBase*);

class TestsBase
{
public:
	void RunAll(const char* className);
	void Assert(bool bExpression);
	void RegisterTest(const char* testName, TestAdapter adapter);

protected:
	void runTest(const char* title, TestAdapter testAdapter);

	void printTitle(const char* title);
	
	virtual void beforeEach();
	virtual void afterEach();

	std::vector<TestAdapter>* pAdapters;
	std::vector<const char*>* pTitles;
};