#include "../include/Cliente.h"
#include <string>
#include <iostream>

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


void Cliente::imprimirCliente()
{
	cout << "----------------------------------------------\n";
	cout << "           CLIENTE ID: " << id << "           \n";
	cout << "----------------------------------------------\n";
	cout << "NOME: " << nome << endl;
	cout << "TELEFONE: " << telefone << endl;
	cout << "MORADA: " << morada << endl;
	cout << "----------------------------------------------\n";
}


