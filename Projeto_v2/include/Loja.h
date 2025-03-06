#pragma once
#include "Cliente.h"
// #include "Auxiliares.h"
#include "Produto.h"
#include <iostream>

class Loja
{
private:

public:
	int contCliente = 0;
	Cliente ListaClientes[100];

	int contProduto = 0;
	Produto Stock[100];
	Loja();
	Loja(Loja &L);
//Cliente
	void adicionarCliente(string nome, string telefone, string morada);
	void mostrarCliente(int id);
	void mostrarClientes();
	int getLastIdCliente();
	int* buscarClientes(string campo, string valor);
	int buscarCliente(string campo, string valor);
	int* tamanhosColunasClientes();

//Produto
	void armazenaProduto(string nome, int quantidade, float preco);
	int buscaProduto( int id);
	void imprimeStock();
	void imprimeProduto(int i);
	void removeProduto(int id);
	int getLastId();
//Vendas

//Relatorios

//Auxiliares
	void preencherDadosIniciais();

};

