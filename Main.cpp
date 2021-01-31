#include <iostream>
#include "DynamicArray.h"

void printArray(DynamicArray<int> arr)
{
	for (int i = 0; i < arr.getLength(); i++) {
		
			std::cout << arr.get(i) << ", ";
	}
}

int main() 
{
	DynamicArray<int> testArr = DynamicArray<int>();
	for(int i = 0; i < 10;i++)
	{
		testArr.push(rand() % 100);
	}
	printArray(testArr);
	
	std::cout << std::endl;
	testArr.sort();
	
	printArray(testArr);
	return 0;
}