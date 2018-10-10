#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class Tree
{
	
	private:
	int pos_raiz = 0;
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

		void addpai(no *pai)
		{
			this->pai = pai;
			if (irmao_direito)
			{
				irmao_direito->addpai(pai);
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

		bool busca_largura(const T chave)
		{
			if (chave == valor)
			{
				return true;
			}
			if (irmao_direito == nullptr && filho_esquerdo)
			{
				return filho_esquerdo->busca_largura(chave);
			}

			if (filho_esquerdo == nullptr && irmao_direito)
			{
				return irmao_direito->busca_largura(chave);
			}

			if (irmao_direito && filho_esquerdo)
			{
				return irmao_direito->busca_largura(chave) || filho_esquerdo->busca_largura(chave);
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

		bool isleaf()
		{
			return filho_esquerdo == nullptr;
		}
	};
	vector<no*> arvore;

	public:
	Tree() = default;
	
	int getPos_raiz(){
		return pos_raiz;
	}

	void setPos_raiz(int new_pos){
		pos_raiz = new_pos;
	}

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

	int busca_vetor(const T chave){
		for(int pos = 0; pos < arvore.size(); pos++){
			if(arvore[pos]->valor == chave){
				return pos;
			}
		}
		return -1;
	}

	void add_por_valor(const T valor, const T chave_busca)
	{
		int pos = busca_vetor(chave_busca);
		if(pos != -1){
			add(valor, pos);
		}
	}

	void remove_por_valor(const T chave_busca)
	{
		int pos = busca_vetor(chave_busca);
		if(pos != -1){
			remove(pos);
		}
	}

	void remove(const int posicao)
	{
		if (posicao > int(arvore.size()))
		{
			return;
		}

		// caso seja raiz
		if (posicao-1 == getPos_raiz())
		{
			if (!arvore[posicao-1]->filho_esquerdo)
			{
				arvore.erase(arvore.begin() + posicao-1);
				//Quando não existe raiz, a variável armazena -1.
				setPos_raiz(-1);
			}
			else
			{
				no * temp = arvore[posicao-1]->filho_esquerdo;
				arvore.erase(arvore.begin() + posicao-1);
				temp->pai = nullptr;
				int new_pos = busca_vetor(temp->valor);
				setPos_raiz(new_pos);
				if (temp->irmao_direito)
				{
					temp->irmao_direito->addpai(temp);
					temp->addfilho(temp->irmao_direito);
					temp->irmao_direito = nullptr;
				}
			}
			return;
		}

		//caso seja folha
		if (arvore[posicao-1]->isleaf())
		{
			if (arvore[posicao-1]->pai->filho_esquerdo == arvore[posicao-1])
			{
				arvore[posicao-1]->pai->filho_esquerdo = arvore[posicao-1]->irmao_direito;
				arvore.erase(arvore.begin() + posicao-1);
			}else
			{
				no *temp = arvore[posicao-1]->pai->filho_esquerdo;
				while (temp->irmao_direito != arvore[posicao-1])
				{
					temp = temp->irmao_direito;
				}
				temp->irmao_direito = arvore[posicao-1]->irmao_direito;
				arvore.erase(arvore.begin() + posicao-1); 
			}

			return;
		}

		//caso seja no interno
		if (arvore[posicao-1] == arvore[posicao-1]->pai->filho_esquerdo)
		{
			arvore[posicao-1]->pai->filho_esquerdo = arvore[posicao-1]->filho_esquerdo;
			if (arvore[posicao-1]->irmao_direito)
			{
				arvore[posicao-1]->pai->filho_esquerdo->addirmao(arvore[posicao-1]->irmao_direito);
			}
			arvore.erase(arvore.begin() + posicao-1); 
		}else
		{
			no *temp = arvore[posicao-1]->pai->filho_esquerdo;
			while (temp->irmao_direito != arvore[posicao-1])
			{
				temp = temp->irmao_direito;
			}
			temp->irmao_direito = arvore[posicao-1]->filho_esquerdo;

			if (arvore[posicao-1]->irmao_direito)
			{
				temp->irmao_direito->addirmao(arvore[posicao-1]->irmao_direito);
			}
			arvore.erase(arvore.begin() + posicao-1); 
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
		return profundidade_no+1;
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
		arvore[pos_raiz]->print();
	}

	bool busca_profundidade(const T chave)
	{
		bool busca = arvore[pos_raiz]->busca_profundidade(chave);
		if (busca)
		{
			return true;
		}
		return false;
	}

	bool busca_largura(const T chave)
	{
		if (int(arvore.size()) == 0)
		{
			return false;	
		}	
		bool busca = arvore[pos_raiz]->busca_largura(chave);
		if (busca)
		{
			return true;
		}
		return false;
	}
};
