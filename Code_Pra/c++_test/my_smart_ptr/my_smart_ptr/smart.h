#ifndef _smart
#define _smart

#include <iostream>
#include <memory>

using namespace std;


template <typename T>
class smart_ptr
{
public:
	//smart_ptr() = 0;
	smart_ptr(T* p = nullptr)
	{
		if(!p)
		{
			this->cnt_ptr = new size_t(0);
			this->data_ptr = nullptr;
		}
		else
		{
			this->cnt_ptr = new size_t(1);
			this->data_ptr = p;
		}
	}

	smart_ptr(const smart_ptr& ptr1)
	{
		this->cnt_ptr = ptr1.cnt_ptr;
		this->data_ptr = ptr1.data_ptr;
		(*this->cnt_ptr)++;
	}

	smart_ptr& operator=(const smart_ptr& p)
	{
		if(data_ptr == p.data_ptr)
		{
			return *this;
		}

		if(*cnt_ptr > 0)
		{
			(*cnt_ptr)--;
		    if((*cnt_ptr) == 0)
		   {
			   delete cnt_ptr;
			   delete data_ptr;
		   }
		}

		
		cnt_ptr = p.cnt_ptr;
		data_ptr = p.data_ptr;
		(*cnt_ptr)++;

		return *this;
	}

	~smart_ptr()
	{
		(*cnt_ptr)--;
		if(*cnt_ptr == 0)
		{
			delete cnt_ptr;
			delete data_ptr;
		}
	}

	size_t use_cnt()
	{
		return *(this->cnt_ptr);
	}


private:
	size_t* cnt_ptr;
	T* data_ptr;
};





#endif