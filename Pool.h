#ifndef POOL_H
#define POOL_H

#include <string>
#include <iostream>
#include <list>

template <typename T>
class ObjectPool
{
public:
	ObjectPool(int min)
		: canCreate(false)
	{
		for (int i = 0; i < min; i++)
		{
			T* newObj = new T();
			newObj->SetEnable(false);
			newObj->SetPool(this);
			resources.push_back(newObj);

		}
	}

	T* getResource()
	{
		if (resources.empty())
		{
			std::cout << "No more left." << std::endl;
			if (canCreate)
			{
				std::cout << "Creating new." << std::endl;
				return new T;
			}
		}
		else
		{
			std::cout << "Reusing existing." << std::endl;
			T* resource = resources.front();

			resource->SetEnable(true);

			resources.pop_front();
			return resource;
		}
	}

	void returnResource(T* object)
	{
		object->Reset();
		object->SetEnable(false);
		resources.push_back(object);
	}

private:

	ObjectPool() { }
	
	bool canCreate;
	std::list<T*> resources;
};

#endif