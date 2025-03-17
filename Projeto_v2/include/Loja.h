#pragma once
#include "Cliente.h"
#include "Vendas.h"
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

	int contVendas = 0;
	Vendas ListaVendas[100];

	int contProdCompra = 0;
	ProdCompra ListaProdCompra[100];

	Loja();
	Loja(Loja &L);
//Cliente
	void adicionarCliente(string nome, string telefone, string morada);
	void removerCliente(int id);
	void mostrarCliente(int id, bool showHeader);
	void mostrarClientes();
	int getLastIdCliente();
	int* buscarClientes(string campo, string valor);
	int buscarCliente(string campo, string valor);
	int* tamanhosColunasClientes();
	int qtdBuscarClientes(string campo, string valor);

//Produto
	void armazenaProduto(string nome, int quantidade, float preco);
	void mostrarProdutos();
	int* tamanhoColunasProdutos();
	int buscaProduto( int id);
	void imprimeProduto(int i);
	void removeProduto(int id);
	void alteraProduto();
	int getLastId();
//Vendas

//Relatorios
	void impRelVendasProd(string nomeProd);
	void impRelVendas(int id);

//Auxiliares
	void preencherDadosIniciais();

};

