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

int Loja::getLastIdCliente()
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

//Produto -------------------------------------------------------------------------------
void Loja::armazenaProduto(string nome, int quantidade, float preco)
{	
	int lastID = getLastId() + 1;
	if (contProduto < 100)
	{
		Stock[contProduto] = Produto(lastID, nome, quantidade, preco);
		contProduto++;
	}
	else
	{
		cout << "Stock cheio!";
	}
}

int Loja::buscaProduto(int id)
{
	for (int i = 0; i < contProduto; i++)
	{
		if (Stock[i].getId() == id)
		{
			return i;
		}
	
	}
	return -1;
}

void Loja::imprimeStock()
{
	for (int i = 0; i < contProduto; i++)
	{
		imprimeProduto(i);
	}
}

void Loja::imprimeProduto(int i)
{
	cout << "[======================================================================================\n";
	cout << endl;
	cout << "                                    PRODUTO\n";
	cout << endl;
	cout << "[======================================================================================\n";
	cout << "| ID | DESCRICAO | QTD | PRECO |\n";
	cout << "________________________________\n";
	cout << Stock[i].toString() << endl << endl;
}

void Loja::removeProduto(int id)
{
	int pos = buscaProduto(id);

	for (pos; pos < contProduto -1; pos++)
	{
		Stock[pos] = Stock[pos + 1];
	}
	contProduto--;
}

int Loja::getLastId()
{
	int maiorID = 0;

	for (int i = 0; i < contProduto; i++)
	{
		int id = Stock[i].getId();
		if ( id > maiorID)
		{
			maiorID = id;
		}


	}
	return maiorID;
}
