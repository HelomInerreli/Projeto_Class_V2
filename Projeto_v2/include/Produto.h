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
	void setNome(string nome);
	void setQuantidade(int quantidade);
	void setPreco(int preco);

	//outras funcoes
	string toString();

};

