#include "Tree.hpp"
#include <iostream>
using namespace std;

int main()
{
	Tree<int> arvore;
	arvore.add(4);
	arvore.add(3, 1);
	
	arvore.print();

	return 0;
}
