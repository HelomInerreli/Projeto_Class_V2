#pragma once

#include <string>

using namespace std;

class Vendas
{
private:
    int talao;
    string dataVenda;
    string cliente;
    float valorTotal;

public:

	Vendas();
	Vendas(int talao, string dataVenda, string cliente, float valorTotal);
    void imprimirVendas(int* tamanho);
    int* tamanhoColunas();
    int getTalao();

    

};

class Carrinho
{
private:
    int idProd;
    string descProd;
    int qtd;
    float preco;
    float precoIva;
    float precoTotal;

public:
    Carrinho();
    Carrinho(int idProd, string descProd, int qtd, float preco, float precoIva, float precoTotal);
    void imprimirCarrinho(int* tamanho);
    int* tamanhoColunas();
    //seletores
	int getId();
	string getDesc();
	int getQuantidade();
	float getPreco();
    float getPrecoIva();
    float getPrecoTotal();
};
