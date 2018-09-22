#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Tree
{
	private:
	struct no
	{
		public:
		T valor;
		no *pai;
		no *filho_esquerdo;
		no *irmao_direito;
		
		no(T valor)
		{
			this->valor = valor;
			pai = nullptr;
			irmao_direito = nullptr;
			filho_esquerdo = nullptr;
		}

		void addirmao(no *irmao)
		{
			if (irmao_direito == nullptr)
			{
				irmao_direito = irmao;
			}
			else
			{
				irmao_direito->addirmao(irmao);
			}
		}
		void addfilho(no *filho)
		{

			if (filho_esquerdo == nullptr)
			{
				filho_esquerdo = filho;
			}
			else
			{
				filho_esquerdo->addirmao(filho);
			}
		}
		
		void print()
		{
			cout << " " << valor;
			if (filho_esquerdo != nullptr)
			{
				filho_esquerdo->print();
			}
			if (irmao_direito != nullptr)
			{
				irmao_direito->print();
			}
		}
	};
	vector<no*> arvore;
	public:
	Tree() = default;
	
	void add(const T valor, int pai = 0)
	{
		if (pai == 0)
		{
			no *novo = new no(valor);
			arvore.push_back(novo);
		}
		else
		{
			no *novo = new no(valor);
			novo->pai = arvore[pai-1];
			arvore.push_back(novo);
			arvore[pai-1]->addfilho(novo);
		}
	}

	void print()
	{
		for (int i = 0; i < arvore.size(); i++)
		{
			if (arvore[i]->pai == nullptr)
			{
				arvore[i]->print();
			}
		}
	}
};
