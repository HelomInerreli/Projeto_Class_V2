#pragma once
#include "Cliente.h"
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
//Cliente
	void adicionarCliente(string nome, string telefone, string morada);
	void mostrarClientes();
	void mostrarProdutos();
	int getLastIdCliente();
	int buscarCliente(string campo, string valor);
	int* tamanhosColunasClientes();
	int* tamanhoColunasProdutos();
//Produto
	void armazenaProduto(string nome, int quantidade, float preco);
	int buscaProduto( int id);
	void imprimeProduto(int i);
	void removeProduto(int id);
	void alteraProduto();
	int getLastId();
//Vendas

//Relatorios

//Auxiliares
	void preencherDadosIniciais();

};

