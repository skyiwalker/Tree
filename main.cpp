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
	arvore.add(9, 3);
	arvore.add(5, 4);
	arvore.add(6, 4);
	arvore.print();
	cout << endl;
	cout << "profundidade de 1: " << arvore.profundidade(4) << endl;
	cout << " altura arvore " << arvore.altura() << endl;
	if (arvore.busca_largura(5))
	{
		cout << "achou" << endl;
	}
	cout << "testando exclusão " << endl;

	arvore.remove(3);
	arvore.add_por_valor(10,6);
	arvore.add_por_valor(11,6);
	arvore.add_por_valor(12,11);
	arvore.add_por_valor(13,12);
	cout << " altura arvore " << arvore.altura() << endl;
	arvore.print();
	return 0;
}
