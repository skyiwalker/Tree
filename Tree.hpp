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
			irmao_direito.addirmao(irmao);
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
			filho_esquerdo.addirmao(filho);
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
};
