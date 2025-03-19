#include "../include/Vendas.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

Auxiliares auxV;

Vendas::Vendas()
{
}

Vendas::Vendas(int talao, string dataVenda, string cliente, float valorTotal)
{
    this->talao = talao;
    this->dataVenda = dataVenda;
    this->cliente = cliente;
    this->valorTotal = valorTotal;
}
void Vendas::imprimirVendas(int* tamanhos)
{string linha = "";
	cout << linha << "\n";
	cout << "| " << auxV.addZero(talao, 2) << " | " << dataVenda;
	for (int i = 0; i <= tamanhos[1] - dataVenda.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << cliente;
	for (int i = 0; i <= tamanhos[2] - cliente.length()+1; i++)
	{
		cout << " ";
	}
	cout << " | " << valorTotal;
	for (int i = 0; i <= tamanhos[3] - to_string(valorTotal).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";

}
int* Vendas::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = to_string(talao).length();
	tamanhos[1] = dataVenda.length();
	tamanhos[2] = cliente.length();
	tamanhos[3] = to_string(valorTotal).length();
	
	return tamanhos;
}



Carrinho::Carrinho()
{
}

Carrinho::Carrinho(int idProd, string descProd, int qtd, float preco, float precoIva, float precoTotal)
{
    this->idProd = idProd;
    this->descProd = descProd;
    this->qtd = qtd;
    this->preco = preco;
    this->precoIva = precoIva;
    this->precoTotal = precoTotal;
}