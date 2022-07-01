#pragma once

template <class T>
class IFactory
{
public:
	virtual T* Create() = 0;
};