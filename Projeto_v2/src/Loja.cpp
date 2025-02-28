#include "../include/Loja.h"
#include "../include/Auxiliares.h"
#include <iostream>

using namespace std;



Loja::Loja()
{

}

void Loja::adicionarCliente(string nome, string telefone, string morada)
{
	int retID = getLastId() + 1;

	if (contCliente < 100)
	{
		ListaClientes[contCliente] = Cliente(retID, nome, telefone, morada);
		contCliente++;
	}
	else
	{
		cout << "Lista de clientes cheia...";
	}

}


void Loja::mostrarClientes()
{
	for (int i = 0; i < contCliente; i++)
	{
		ListaClientes[i].imprimirCliente();
	}
}

int Loja::getLastId()
{
	int maiorId = 0;

	for (int i = 0; i < contCliente; i++)
	{
		int id = ListaClientes[i].getId();
		if ( id > maiorId)
		{
			maiorId = id;
		}
	}
	return maiorId;
}

int Loja::buscarCliente(string campo, string valor)
{
	//campo = textToUpper(campo);
	//if (campo == "ID")
	//{

	//}

	return 0;
}