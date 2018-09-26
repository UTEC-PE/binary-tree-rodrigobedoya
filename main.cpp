#include <iostream>
#include "tree.h"

int main()
{
	Tree test;
	test.insert(5);
	test.insert(3);
	test.insert(4);
	test.insert(2);
	test.insert(6);
	test.insert(7);
	test.insert(8);
	
	test.printInOrder();
	test.printPreOrder();
	test.printPostOrder();
	std::cout << *(test.begin()+2) << std::endl;
	std::cout << test.getWeight() << std::endl;
	std::cout << test.height() << std::endl;
	return 0;
}

//TODO: remove