#include "../include/Vendas.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

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
void Carrinho::imprimirCarrinho(int* tamanhos)
{string linha = "";
	cout << linha << "\n";
	cout << "| " << auxV.addZero(idProd, 2) << " | " << descProd;
	for (int i = 0; i <= tamanhos[1] - descProd.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << qtd;
	for (int i = 0; i <= tamanhos[2] - to_string(qtd).length()+1; i++)
	{
		cout << " ";
	}
	cout << " | " << preco;
	for (int i = 0; i <= tamanhos[3] - to_string(preco).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
    for (int i = 0; i <= tamanhos[4] - to_string(precoIva).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
    for (int i = 0; i <= tamanhos[5] - to_string(precoTotal).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";

}
int* Carrinho::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = descProd.length();
	tamanhos[1] = to_string(qtd).length();
	tamanhos[2] = to_string(preco).length();
	tamanhos[3] = to_string(precoIva).length();
    tamanhos[4] = to_string(precoTotal).length();
	
	return tamanhos;
}

ProdCompra::ProdCompra()
{
}

ProdCompra::ProdCompra(int talao, int idProd, string descProd, int qtd, float preco)
{
    this->talao = talao;
    this->idProd = idProd;
    this->descProd = descProd;
    this->qtd = qtd;
    this->preco = preco;
}
void ProdCompra::imprimirCompra(int* tamanhos)
{string linha = "";
	cout << linha << "\n";
	cout << "| " << auxV.addZero(idProd, 2) << " | " << talao;
	for (int i = 0; i <= tamanhos[1] - to_string(talao).length(); i++)
	{
		cout << " ";
	}
	cout << " | " << idProd;
	for (int i = 0; i <= tamanhos[2] - to_string(idProd).length()+1; i++)
	{
		cout << " ";
	}
	cout << " | " << descProd;
	for (int i = 0; i <= tamanhos[3] - descProd.length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
    for (int i = 0; i <= tamanhos[3] - to_string(qtd).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
    for (int i = 0; i <= tamanhos[3] - to_string(preco).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";

}
int* ProdCompra::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = to_string(talao).length();
	tamanhos[1] = to_string(idProd).length();
	tamanhos[2] = descProd.length();
	tamanhos[3] = to_string(qtd).length();
    tamanhos[4] = to_string(preco).length();
	
	return tamanhos;
}