#include "../include/Vendas.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

using namespace std;

// Auxiliares aux;

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

void ProdCompra::imprimirProdCompra(int* tamanhos)
{
    string linha = "| " + to_string(talao);
    for (int i = 0; i < tamanhos[0] - to_string(talao).length(); i++)
    {
        linha += " ";
    }
    linha += " | " + dataVenda;
    for (int i = 0; i < tamanhos[1] - dataVenda.length(); i++)
    {
        linha += " ";
    }
    linha += " | " + cliente;
    for (int i = 0; i < tamanhos[2] - cliente.length(); i++)
    {
        linha += " ";
    }
    linha += " | " + arredondar(valorTotal);
    for (int i = 0; i < tamanhos[3] - arredondar(valorTotal).length(); i++)
    {
        linha += " ";
    }
    linha += "  |";
    cout << linha << "\n";
}