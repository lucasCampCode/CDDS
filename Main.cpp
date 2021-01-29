#include <iostream>
#include "DynamicArray.h"

template<typename T>
void printArray(T arr, int length)
{
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << ", ";
	}
}

int main() 
{
	DynamicArray<int,5> testArr = DynamicArray<int,5>();
	
	printArray(testArr, testArr.getLength());
	
	std::cout << std::endl;

	
	printArray(testArr, testArr.getLength());
	return 0;
}