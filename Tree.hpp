#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Tree
{
	private:
	struct no
	{
		T valor;
		int pai;
		int filho_esquerdo;
		int irmao_direito;
		
		no(T valor, int pai)
		{
			this->valor = valor;
			this->pai = pai;
			filho_esquerdo = -1;
			irmao_direito = -1;
		}
		
		
	};
	
	vector<no> arvore;
	
	public:
	Tree() = default;
	void add(T valor, int pai = -1)
	{
		if (pai > arvore.size())
		{
			return;
		}
		
		arvore.push_back(no(valor, pai));
		arvore[pai-1].addfilho(arvore.size());
	}
	
	void print()
	{
		for (int i = 0; i<arvore.size(); i++)
		{
			if (arvore[i].pai == -1)
			{
				cout << arvore[i].valor;
				
			}
		}	
	}
	
};
