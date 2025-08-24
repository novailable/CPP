#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int &n) 
{
	n += 1;
	std::cout << n << " ";
}

void printConstInt(const int &n)
{
	std::cout << n << " ";
}


void printString(std::string &s)
{
	s += "_";
	std::cout << s << " ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t arrLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array + increment: ";
	iter(arr, arrLen, printInt);
	std::cout << "\n\n";

	const int constArr[] = {10, 20, 30};
	std::cout << "Const array print: ";
	iter(const_cast<int*>(constArr), 3, printConstInt);
	std::cout << "\n\n";

	std::string strArr[] = {"apple", "banana", "cherry"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "Modified strings: ";
	iter(strArr, strLen, printString);
	std::cout << "\n\n";

	return 0;
}
