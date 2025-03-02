#include "../include/Produto.h"
#include <iomanip>

Produto::Produto()
{
}

Produto::Produto(int id, string nome, int quantidade, float preco) {
	this->id = id;
	this->nome = nome;
	this->quantidade = quantidade;
	this->preco = preco;
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





