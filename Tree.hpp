#include <vector>
#include <iostream>

using std::cout;
using std::vector;

template <typename T>
class Tree
{
	private:
	struct No
	{
		public:
		T valor;
		No *filho_esquerdo;
		No *irmao_direito;
		No *pai;

		No(const T valor)
		{
			this->valor = valor;
			pai = nullptr;
			filho_esquerdo = nullptr;
			irmao_direito = nullptr;
		}
		No(const T valor, No *pai)
		{
			this->valor = valor;
			this->pai = pai;
			irmao_direito = nullptr;
			filho_esquerdo = nullptr;
		}

		void addfilho(No *filho)
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
		void addirmao(No *irmao)
		{
			if (irmao_direito == nullptr)
			{
				irmao_direito = irmao;
			}else
			{
				irmao_direito->addirmao(irmao);
			}
		}

	};	
	vector<No> arvore;
	
	public:
	Tree() = default;
	~Tree()
	{
		vector<No>().swap(arvore);
	}

	void add(const T valor, int posicao_pai = 0)
	{
		if (posicao_pai > arvore.size())
		{
			return;
		}

		if (posicao_pai == 0)
		{
			arvore.push_back(No(valor));
		}else
		{
			arvore.push_back(No(valor, &arvore[posicao_pai-1]));
			arvore[posicao_pai-1].addfilho(&arvore[arvore.size()-1]);
		}

	}
};