#pragma once

#include <string>

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
	void showMenu();

};

