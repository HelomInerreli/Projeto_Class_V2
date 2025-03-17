#pragma once

#include <string>
#include "Loja.h"

using namespace std;

class Auxiliares
{
private:

public:
	string textToUpper(string text);
	string addZero(int num, int digitos);
	string arredondar(float num);
	string getDateTime();
	bool validNum(string valor);
	bool sorteio(int nSorte, float minCompra, float valorCompra);

	// Funcoes para menus
	void showMenu();
	void showMenuClientes(Loja L2);
	void showMenuAltCliente(int id, Loja L2);
	void showMenuAddCliente(Loja L);
	void showMenuBuscaCliente(Loja L);


	void showMenuStock(Loja L);
	void showMenuAddProdutos(Loja L);
	void showMenuAltProd(Loja L, int id);

	void showMenuVendas(Loja L);
	void showMenuNovaVenda(Loja L);
	
};

