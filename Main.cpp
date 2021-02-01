
#include "DynamicArray.h"



int main() 
{
	srand(time(NULL));
	DynamicArray<int> testArr = DynamicArray<int>();

	for(int i = 0; i < 10; i++)
	{
		testArr.push(rand() % 10);
	}

	testArr.print();
	std::cout << std::endl;
	testArr.sort();
	std::cout << testArr.pop() << std::endl;
	std::cout << std::endl;
	testArr.print();
	system("pause");
	return 0;
}