#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdio.h>
#include <assert.h>

typedef unsigned int uint;

template <class TYPE>

class mVector
{
private:

	TYPE *buffer;
	uint capacity = 10;
	uint elements = 0;

public:

	mVector()
	{
		buffer = new TYPE[capacity]; 
	};

	mVector(const mVector& copyvector) : capacity(copyvector.capacity), elements(copyvector.elements)
	{
		buffer = new TYPE[capacity];
		elements = copyvector.elements;
		for (uint i = 0; i < elements; i++)
			buffer[i] = copyvector.buffer[i];

	};

	mVector(uint ncapacity) : capacity(ncapacity)
	{
		buffer = new TYPE[capacity];
	}

	~mVector()
	{
		delete[] buffer;
	};

	int size() const
	{
		return capacity;
	}

	int nelements() const
	{
		return elements;
	}

	void push_back(const TYPE& pushbuffer)
	{		
			if (elements == capacity)
			{
				TYPE *temp = new TYPE[ 2*capacity];
				for (uint i = 0; i < elements; i++)
					temp[i] = buffer[i];
				delete[] buffer;
				buffer = temp;
				delete[] temp;
			}
			*(buffer + (elements++)) = pushbuffer;
			
	}

	void push_front(const TYPE& pushbuffer)
	{
		
		if (elements == capacity)
		{
			capacity *= 2;
			TYPE *temp = new TYPE[capacity];	
			for (int i = 0; i < elements; i++)
				temp[i] = buffer[i];
			delete[] buffer;
			buffer = temp;
		}
		for (int i = elements; i >= 0; --i)
				buffer[i +1] = buffer[i];
		
		buffer[0] = pushbuffer;
		++elements;
	}

	bool pop_back()
	{
		if (elements > 0)
		{
			elements--;
			return true;
		}
		return false;
	}

	bool pop_front()
	{
		if (elements > 0)
		{
			for (int i = 0; i < elements; i++)
			{
				buffer[i] = buffer[i + 1];
			}
			elements--;
			return true;
		}
		return false;
	}

	TYPE operator[](int index) const
	{
		assert(index < elements);
		return buffer[index];
	}

	TYPE& operator[](int index)
	{
		assert(index < elements);
		return buffer[index];
	}

	bool empty() const
	{
		return (elements == 0) == 1;
	}

	void clean()
	{
		elements = 0;
	}

};

#endif;