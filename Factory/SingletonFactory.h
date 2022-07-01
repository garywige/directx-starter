#pragma once
#include "IFactory.h"

template <class T>
class SingletonFactory : IFactory<T>
{
public:
	SingletonFactory();

	~SingletonFactory();

	T* Create();

protected:
	T* pSingleton;
};
