#ifndef ARRAY_TPP
#define ARRAY_TPP

// Default constructor: empty array, nothing is allocated
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

// Size constructor: n value-initialized elements
template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
	if (n > 0)
		_elements = new T[n]();
}

// Copy constructor: deep copy of the other array
template <typename T>
Array<T>::Array(Array const &other) : _elements(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}
}

// Assignment operator: allocate and copy first, then free the old memory
template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		T	*newElements = NULL;

		if (other._size > 0)
		{
			newElements = new T[other._size];
			for (unsigned int i = 0; i < other._size; i++)
				newElements[i] = other._elements[i];
		}
		delete[] _elements;
		_elements = newElements;
		_size = other._size;
	}
	return *this;
}

// Destructor: delete[] on NULL is safe
template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

// Element access with bounds check (writable)
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

// Element access with bounds check (read-only, for const arrays)
template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}

#endif