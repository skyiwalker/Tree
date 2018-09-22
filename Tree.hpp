#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct no
{
	T valor;
	no<T> *pai;
	no<T> *filho_esquerdo;
	no<T> *irmao_direito;
	
	no(T valor)
	{
		this->valor = valor;
		this->pai = nullptr;
		this->irmao_direito = nullptr;
		this->filho_esquerdo = nullptr;
	}
	no(T valor, no<T> *pai)
	{
		this->valor = valor;
		this->pai = pai;
		filho_esquerdo = nullptr;
		irmao_direito = nullptr;
	}
	void addirmao(no<T> *irmao)
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
	void addfilho(no<T> *filho)
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
	void printno()
	{
		cout << valor << " ";
		if (filho_esquerdo != nullptr)
		{
			filho_esquerdo->printno();
		}
		if (irmao_direito != nullptr)
		{
			irmao_direito->printno();
		}
	}		
};

template <typename T>
class Tree
{
	private:
	vector< no <T> > arvore;
	
	public:
	Tree() = default;
	
	void add(const T valor, no<T> *pai = NULL)
	{
		arvore.push_back(no<T>(valor, pai));
		no<T> *temp = arvore[arvore.size()-1];
		pai.addfilho(temp); 
	}
	void add(const T valor, int pai = 0)
	{
		if (pai == 0)
		{
			arvore.push_back(no<T>(valor));
		}
		else
		{
			arvore.push_back(no<T>(valor, &arvore[pai-1]));
			no<T> *temp = &arvore[arvore.size()-1];
			arvore[pai-1].addfilho(temp);
		}
	}
	void print()
	{
		for (auto i: arvore)
		{
			if (i.pai == nullptr)
			{
				i.printno();
			}
		}
	}
};
