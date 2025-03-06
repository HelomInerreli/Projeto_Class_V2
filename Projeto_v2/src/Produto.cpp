#include "../include/Produto.h"
#include <iomanip>
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

Produto::Produto()
{
}

Produto::Produto(int id, string nome, int quantidade, float preco) {
	this->id = id;
	this->nome = nome;
	this->quantidade = quantidade;
	this->preco = preco;
}
void Produto::imprimirProduto(int* tamanhos)
{
string linha = "";
	cout << linha << "\n";
	Auxiliares aux;
	cout << "| " << aux.addZero(id, 2) << " | " << nome;
	for (int i = 0; i <= tamanhos[1] - nome.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << quantidade;
	for (int i = 0; i <= tamanhos[2] - to_string(quantidade).length()+1; i++)
	{
		cout << " ";
	}
	cout << " | " << preco;
	for (int i = 0; i <= tamanhos[3] - to_string(preco).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";
}

int* Produto::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = to_string(id).length();
	tamanhos[1] = nome.length();
	tamanhos[2] = to_string(quantidade).length();
	tamanhos[3] = to_string(preco).length();
	
	return tamanhos;
}

int Produto::getId() 
{
	return id;
}

string Produto::getNome()
{
	return nome;
}

int Produto::getQuantidade()
{
	return quantidade;
}

float Produto::getPreco()
{
	return preco;
}

void Produto::setNome(string nome)
{
	this->nome = nome;
}

void Produto::setQuantidade(int quantidade)
{
	this->quantidade = quantidade;
}

void Produto::setPreco(int preco)
{
	this->preco = preco;
}

string Produto::toString()
{
	return "| " + to_string(id) + "  |   " + nome + "   | " + to_string(quantidade) + "  |  " + to_string(preco) + "|";
}





