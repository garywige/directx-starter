#include "SingletonFactoryTests.h"
#include "GameLoopTests.h"

int main()
{
	SingletonFactoryTests().RunAll("SingletonFactory");
	GameLoopTests().RunAll("GameLoop");
}

