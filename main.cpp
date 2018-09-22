#include "Tree.hpp"
#include <iostream>
using namespace std;

int main()
{
	Tree<int> arvore;
	arvore.add(3, 0);
	arvore.add(4, 1);
	arvore.add(2, 1);
	arvore.add(1, 2);
	arvore.print();
	cout << "profundidade de 1: " << arvore.profundidade(4);
	return 0;
}
