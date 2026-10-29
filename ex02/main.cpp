#include <iostream>
#include <string>
#include "Array.hpp"

// Print all elements; uses the const version of operator[]
template <typename T>
void printArray(Array<T> const &arr, std::string const &name)
{
	std::cout << name << " (size " << arr.size() << "): ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "--- hint: new int() ---" << std::endl;
	int	*a = new int();
	std::cout << "*a = " << *a << std::endl;
	delete a;

	std::cout << "\n--- empty array ---" << std::endl;
	Array<int>	empty;
	std::cout << "size: " << empty.size() << std::endl;
	try
	{
		empty[0] = 1;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- array of n elements ---" << std::endl;
	Array<int>	nums(5);
	printArray(nums, "nums");
	for (unsigned int i = 0; i < nums.size(); i++)
		nums[i] = i * 10;
	printArray(nums, "nums");

	std::cout << "\n--- copy constructor ---" << std::endl;
	Array<int>	copy(nums);
	copy[0] = 999;
	printArray(nums, "nums");
	printArray(copy, "copy");

	std::cout << "\n--- assignment operator ---" << std::endl;
	Array<int>	assigned(2);
	assigned = nums;
	assigned[1] = -1;
	printArray(nums, "nums");
	printArray(assigned, "assigned");

	std::cout << "\n--- self-assignment ---" << std::endl;
	Array<int>	&ref = assigned;
	assigned = ref;
	printArray(assigned, "assigned");

	std::cout << "\n--- out of bounds ---" << std::endl;
	try
	{
		nums[5] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		int	negative = -1;
		nums[negative] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- string array ---" << std::endl;
	Array<std::string>	words(3);
	words[0] = "hello";
	words[1] = "world";
	words[2] = "42";
	printArray(words, "words");

	std::cout << "\n--- const array ---" << std::endl;
	Array<int> const	constNums(nums);
	std::cout << "constNums[2] = " << constNums[2] << std::endl;
	// Does not compile: const operator[] returns a const reference
	// constNums[2] = 5;

	return 0;
}