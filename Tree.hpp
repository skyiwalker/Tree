#include <vector>
#include <iostream>

using std::cout
using std::vector

template <typename T>
class Tree
{
	private:	
	struct No
	{
		public:
		T valor;
		int filho_esquerdo;
		int pai;
		int irmao_direito;

		No() = default;
	};

	vector<No> arvore;
	
	public:
	Tree() = default;
	~Tree()
	{
		vector<No>().swap(arvore);
	}

	unsigned int busca()
	{
		
	}
	
};