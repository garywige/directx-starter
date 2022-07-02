#include "SingletonFactory.h"

template <class T>
SingletonFactory<T>::SingletonFactory()
{
	pSingleton = 0;
}

template<class T>
SingletonFactory<T>::~SingletonFactory()
{
	if (pSingleton) delete pSingleton;
}

template<class T>
T* SingletonFactory<T>::Create()
{
	return pSingleton ? pSingleton : pSingleton = new T();
}


void libLinker()
{
	SingletonFactory<int> link = SingletonFactory<int>();
}