#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include "Defs.h"


template <class TYPE>
class MyQueue
{
public:

	TYPE* data = NULL;
	int numElements = 0;
	int capacity = BLOCK;

	MyQueue()
	{
		data = new TYPE[capacity];
	}
		
	MyQueue(uint size) 
	{
		capacity = BLOCK * ((size / BLOCK) + 1);
		data = new TYPE[capacity];
	}

	bool empty()
	{
		return numElements == 0;
	}

	uint size()
	{
		return numElements;
	}

	const TYPE* back()
	{
		return data[(numElements - 1)];
	}

	void pushback(const TYPE& element)
	{
		if (numElements == capacity)
		{
			uint newSize = capacity += BLOCK;
			TYPE* tmp = new TYPE[newSize];

			memcpy(tmp, data, numElements * sizeof(TYPE));
			delete[] data;
			data = tmp;
		}
		data[numElements++] = element;
			
	}

	bool popfront(TYPE& buffer)
	{
		bool ret = false;

		if (numElements > 0)
		{
			buffer = data[0];
			memcpy(data,data+1,sizeof(TYPE)*(--numElements));
			ret = true;
		}
		return ret;
	}


	void CleanUp()
	{
		delete[] data;
	}



};
#endif


