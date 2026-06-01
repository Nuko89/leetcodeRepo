#include "Vector.h" // include definition of class vector


// empty container constructor (default constructor)
// Constructs an empty container, with no elements.
vector::vector()
{
	myFirst = myLast = myEnd = nullptr;
}

//寫 
// fill constructor
// Constructs a container with "count" elements.
// Each element is initialized as 0.
vector::vector(const size_type count)//size_type == string或vector的長度 
{
	if (count != 0) {
		myFirst = new int[count]();
		myLast = myEnd = myFirst + count;
	}
}

//寫 
// copy constructor
// Constructs a container with a copy of each of the elements in "right",
// in the same order.
vector::vector(const vector &right)
{
	resize(right.myLast - right.myFirst);

	//複製內容
	for (int i = 0; i < right.myLast - right.myFirst; i++)
	{
		*(myFirst + i) = *(right.myFirst + i);
	}
}

// Vector destructor
// Destroys the container object.
// Deallocates all the storage capacity allocated by the vector.
vector::~vector()
{
	if (myFirst != nullptr)
		delete[] myFirst;
}

// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the vector size by one,
// which causes an automatic reallocation of the allocated storage space
// if and only if the new vector size surpasses the current vector capacity.
void vector::push_back(const value_type &val)
{
	size_type originalSize = size();
	resize(originalSize + 1);
	myFirst[originalSize] = val;
}

//寫 
// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
// Copies all the elements from "right" into the container
// (with "right" preserving its contents).
vector& vector::assign(const vector &right)
{
	if (this != &right) // avoid self-assignment
	{
		if (capacity() < right.myLast - right.myFirst)//變大
		{
			resize(right.myLast - right.myFirst);
		}
		else
		{
			myLast = myFirst + (right.myLast - right.myFirst);
		}
		
		//複製內容
		for (int i = 0; i < right.myLast - right.myFirst; i++)
		{
			*(myFirst + i) = *(right.myFirst + i);
		}
	}
	return *this; // enables x = y = z, for example
}

//寫 
// Resizes the vector so that it contains newSize elements.
// If newSize is smaller than the current vector size,
// the content is reduced to its first newSize elements, removing those beyond.
// If newSize is greater than the current vector size,
// the content is expanded by inserting at the end
// as many elements as needed to reach a size of newSize.
// The new elements are initialized as 0.
// If newSize is also greater than the current vector capacity,
// an automatic reallocation of the allocated storage space takes place.
void vector::resize(const size_type newSize)
{
	if (myFirst == nullptr)//處理一開始沒指向
	{
		myFirst = new int[newSize]();
		myLast = myEnd = myFirst + newSize;
	}
	else
	{
		if (capacity() >= newSize)//變小or不變
		{
			myLast = myFirst + newSize;
		}
		else
		{
			int i = capacity();
			if (i * 1.5 < newSize) i = newSize;
			else i *= 1.5;
			int *temPtr = myFirst;
			int oldSize = size();

			//要一個空間
			myFirst = new int[i]();

			//指標指好
			myLast = myFirst + newSize;
			myEnd = myFirst + i;

			//複製內容
			for (int i = 0; i < oldSize; i++)
			{
				*(myFirst + i) = *(temPtr + i);
			}

			//delete[] temPtr;
		}
	}
}

// Removes the last element in the vector,
// effectively reducing the container size by one.
void vector::pop_back()
{
	if (size() > 0)
		--myLast;
}

// Removes all elements from the vector (which are destroyed),
// leaving the container with a size of 0.
// A reallocation is not guaranteed to happen,
// and the vector capacity is not guaranteed to change due to calling this function.
void vector::clear()
{
	myLast = myFirst;
}

// Returns an iterator pointing to the first element in the vector.
// If the container is empty, the returned iterator value shall not be dereferenced.
vector::pointer vector::begin()
{
	return myFirst;
}

// Returns the number of elements in the vector.
// This is the number of actual objects held in the vector,
// which is not necessarily equal to its storage capacity.
vector::size_type vector::size()
{
	return (myLast - myFirst);
}

// Returns the size of the storage space currently allocated for the vector,
// expressed in terms of elements.
// This capacity is not necessarily equal to the vector size.
// It can be equal or greater, with the extra space allowing to accommodate
// for growth without the need to reallocate on each insertion.
vector::size_type vector::capacity()
{
	return (myEnd - myFirst);
}

// Returns a reference to the element at position "pos" in the vector container.
vector::value_type& vector::element(const size_type pos)
{
	return myFirst[pos];
}
