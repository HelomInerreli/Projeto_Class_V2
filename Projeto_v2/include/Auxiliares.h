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
};

