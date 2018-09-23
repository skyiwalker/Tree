#include <iostream>
#include <vector>
#include <algorithm>
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

		bool busca_profundidade(const T chave)
		{
			if (valor == chave)
			{
				return true;
			}
			if (filho_esquerdo && irmao_direito)
			{
				return filho_esquerdo->busca_profundidade(chave) || irmao_direito->busca_profundidade(chave);
			}
			if (filho_esquerdo)
			{
				return filho_esquerdo->busca_profundidade(chave);
			}
			if (irmao_direito)
			{
				return irmao_direito->busca_profundidade(chave);
			}
			return false;
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
	
	void add(const T valor, const int pai = 0)
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

	unsigned profundidade(const int posicao_no)
	{
		if (posicao_no > int(arvore.size()))
		{
			return 0;
		}
		int profundidade_no = 0;
		no *temp = arvore[posicao_no-1]->pai;
		while(temp)
		{
			profundidade_no++;
			temp = temp->pai;
		}
		return profundidade_no;
	}

	unsigned altura()
	{
		int max = 0; 
		for (int i = 1; i <= int(arvore.size()); i++)
		{
			if (int(profundidade(i)) > max)
			{
				max = profundidade(i);
			}
		}
		return max;
	}

	void print()
	{
		for (int i = 0; i < int(arvore.size()); i++)
		{
			if (arvore[i]->pai == nullptr)
			{
				arvore[i]->print();
			}
		}
	}

	bool busca_profundidade(const T chave)
	{
		for (int i = 0; i < int(arvore.size()); i++)
		{
			if (arvore[i]->pai == nullptr)
			{
				bool busca = arvore[i]->busca_profundidade(chave);
				if (busca)
				{
					return true;
				}
			}
		}
		return false;
	}
};
