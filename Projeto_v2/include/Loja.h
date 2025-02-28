#pragma once
#include "Cliente.h"
#include "Auxiliares.h"

class Loja
{
private:
	Cliente ListaClientes[100];
	int contCliente = 0;

public:
	Loja();
	void adicionarCliente(string nome, string telefone, string morada);
	void mostrarClientes();

	int getLastId();
	int buscarCliente(string campo, string valor);
};

