#ifndef _unique
#define _unique


#include <iostream>
using namespace std;




template<typename T> class my_unique
{
public:
	my_unique(T* p = nullptr);
	~my_unique();

	T* get_ptr()
	{
		return data_ptr;
	}

	T* operator->() const
	{
		if(this->data_ptr)
		{
			return this->data_ptr;
		}
	}

	T& operator*() const
	{
		if(this->data_ptr)
		{
			return *(this->data_ptr);
		}
	}

	T* release();
	void reset(T* p);
private:
	T* data_ptr;

	my_unique(const my_unique& ptr);
	my_unique& operator=(const my_unique& ptr);
	
};


template <typename T> 
my_unique<T>::my_unique(T* p = nullptr):data_ptr(p)
{

}


template <typename T>
my_unique<T>::~my_unique()
{
	delete data_ptr;
	data_ptr = nullptr;
}

template <typename T>
T* my_unique<T>::release()
{
	T* res = data_ptr;
	data_ptr = nullptr;
	return res;
}

template <typename T>
void my_unique<T>::reset(T* p)
{
	delete data_ptr;
	data_ptr = p;
}


#endif