#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

// Function template: reads the element only (const reference)
template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
}

// Function template: modifies the element (non-const reference)
template <typename T>
void increment(T &x)
{
	x++;
}

// Regular function: modifies a string in place
void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::toupper(static_cast<unsigned char>(s[i]));
}

int main(void)
{
	// int array: read, modify, read again
	int nums[] = {1, 2, 3, 4, 5};
	size_t const numsLen = 5;

	std::cout << "int array:          ";
	::iter(nums, numsLen, print<int>);
	std::cout << std::endl;

	::iter(nums, numsLen, increment<int>);
	std::cout << "after increment:    ";
	::iter(nums, numsLen, print<int>);
	std::cout << std::endl;

	// string array: template function and regular function
	std::string words[] = {"hello", "world", "42"};
	size_t const wordsLen = 3;

	std::cout << "string array:       ";
	::iter(words, wordsLen, print<std::string>);
	std::cout << std::endl;

	::iter(words, wordsLen, toUpper);
	std::cout << "after toUpper:      ";
	::iter(words, wordsLen, print<std::string>);
	std::cout << std::endl;

	// const array: only const-reference functions are allowed
	double const vals[] = {1.5, 2.5, 3.5};
	size_t const valsLen = 3;

	std::cout << "const double array: ";
	::iter(vals, valsLen, print<double>);
	std::cout << std::endl;

	// Does not compile: cannot modify elements of a const array
	// ::iter(vals, valsLen, increment<double>);

	return 0;
}