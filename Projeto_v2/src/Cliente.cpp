#include "../include/Cliente.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

using namespace std;

Auxiliares A;

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

string Cliente::getNome()
{
	return nome;
}

string Cliente::getTelefone()
{
	return telefone;
}

string Cliente::getMorada()
{
	return morada;
}

void Cliente::updateNome()
{
	cout << "Informe o novo nome para o cliente: ";
	cin.ignore();
	getline(cin, nome);
}

void Cliente::updateTelefone()
{
	string novoValor;
	cout << "Informe o novo telefone para o cliente: ";
	cin.ignore();
	getline(cin, novoValor);
	while (!A.validNum(novoValor) && A.textToUpper(novoValor) != "R")
	{
		cout << "Valor inserido não é um número.\n";
		cout << "Informe o novo telefone para o cliente: ";
		cin.ignore();
		getline(cin, novoValor);
	}

	if (A.textToUpper(novoValor) != "R")
	{
		telefone = novoValor;
	}
	else	
	{
		return;
	}
	
}

void Cliente::updateMorada()
{
	cout << "Informe a nova morada para o cliente: ";
	cin.ignore();
	getline(cin, morada);
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
