#include "../include/Cliente.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

using namespace std;

Cliente::Cliente()
{

}

Cliente::Cliente(int id, string nome, string telefone, string morada)
{
	this->id = id;
	this->nome = nome;
	this->telefone = telefone;
	this->morada = morada;
}

int Cliente::getId()
{
	return id;
}


void Cliente::imprimirCliente(int* tamanhos)
{
	string linha = "";
	cout << linha << "\n";
	Auxiliares aux;
	cout << "| " << aux.addZero(id, 2) << " | " << nome;
	for (int i = 0; i <= tamanhos[1] - nome.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << telefone;
	for (int i = 0; i <= tamanhos[2] - telefone.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << morada;
	for (int i = 0; i <= tamanhos[3] - morada.length(); i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";
}

int* Cliente::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = to_string(id).length();
	tamanhos[1] = nome.length();
	tamanhos[2] = telefone.length();
	tamanhos[3] = morada.length();
	
	return tamanhos;
}
