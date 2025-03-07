#pragma once
#include<iostream>
#include<string>
using namespace std;

class Produto
{
private:
	//atributos
	int id;
	string nome;
	int quantidade;
	float preco;


public:
	//construtor
	Produto();
	Produto(int id, string nome, int quantidade, float preco);

	//seletores
	int getId();
	string getNome();
	int getQuantidade();
	float getPreco();

	//modificadores
	void setNome();
	void setQuantidade();
	void setPreco();

	//outras funcoes
	string toString();
	void imprimirProduto(int* tamanhos);
	int* tamanhoColunasProdutos();
	int* tamanhoColunas();
	void menuAtlProd();
};

