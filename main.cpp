#include "Tree.hpp"
#include <iostream>
using namespace std;

int main()
{
	Tree<int> arvore;
	arvore.add(3, 0);
	arvore.add(4, 1);
	arvore.add(1, 2);
	arvore.add(2, 1);
	arvore.print();
	return 0;
}
