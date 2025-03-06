#pragma once

#include <string>

using namespace std;

class Cliente
{
private:
	int id;
	string nome;
	string telefone;
	string morada;



public:

	Cliente();
	Cliente(int id, string nome, string telefone, string morada);

	////Fun��es seletoras
	int getId();
	string getNome();
	string getTelefone();
	string getMorada();

	//Funções de modificações
	void updateNome();
	void updateTelefone();
	void updateMorada();

	//Auxiliares
	void imprimirCliente(int* tamanhos);
	int* tamanhoColunas();

};

