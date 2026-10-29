#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Call func on every element of the array
template <typename T, typename F>
void iter(T *array, size_t const length, F func)
{
	if (array == NULL)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif