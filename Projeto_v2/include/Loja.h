#pragma once
#include "Cliente.h"
#include "Auxiliares.h"
#include "Produto.h"
#include <iostream>

class Loja
{
private:
	int contCliente = 0;
	Cliente ListaClientes[100];

	int contProduto = 0;
	Produto Stock[100];


public:
	Loja();
//Cliente
	void adicionarCliente(string nome, string telefone, string morada);
	void mostrarClientes();
	int getLastIdCliente();
	int buscarCliente(string campo, string valor);
//Produto
	void armazenaProduto(string nome, int quantidade, float preco);
	int buscaProduto( int id);
	void imprimeStock();
	void imprimeProduto(int i);
	void removeProduto(int id);
	int getLastId();
};

