#include "../include/Produto.h"
#include <iomanip>
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>
Auxiliares A;

Produto::Produto()
{
}

Produto::Produto(int id, string nome, int quantidade, float preco) {
	this->id = id;
	this->nome = nome;
	this->quantidade = quantidade;
	this->preco = preco;
}

void Produto::imprimirProduto(int* tamanhos)
{
string linha = "";
	cout << linha << "\n";
	cout << "| " << A.addZero(id, 2) << " | " << nome;
	for (int i = 0; i <= tamanhos[1] - nome.length(); i++)
	{
		cout << " ";
	}
	cout << " | " << quantidade;
	for (int i = 0; i <= tamanhos[2] - to_string(quantidade).length()+1; i++)
	{
		cout << " ";
	}
	cout << " | " << preco;
	for (int i = 0; i <= tamanhos[3] - to_string(preco).length()+3; i++)
	{
		cout << " ";
	}
	cout << " |";
	cout << linha << "\n";
}

int* Produto::tamanhoColunas()
{
	int* tamanhos = new int[4];
	tamanhos[0] = to_string(id).length();
	tamanhos[1] = nome.length();
	tamanhos[2] = to_string(quantidade).length();
	tamanhos[3] = to_string(preco).length();
	
	return tamanhos;
}

int Produto::getId() 
{
	return id;
}

string Produto::getNome()
{
	return nome;
}

int Produto::getQuantidade()
{
	return quantidade;
}

float Produto::getPreco()
{
	return preco;
}

void Produto::setNome()
{
	cout << "Informe o novo nome para o produto: ";
            cin.ignore();
            getline(cin, nome);
}

void Produto::setQuantidade()
{	string novoValor;
	cout << "Informe a nova quantidade para o produto: ";
            cin >> novoValor;
            while (!A.validNum(novoValor) && A.textToUpper(novoValor) != "R")
            {
                cout << "Valor inserido não é um número.\n";
                cout << "Informe a nova quantidade para o produto: ";
                cin >> novoValor;
            }
			if (A.textToUpper(novoValor) != "R")
			{
				quantidade=stoi(novoValor);
			}
			else
			{
				return;
			}
			
			
}

void Produto::atualizaQuantidade(int qtd)
{
	quantidade = qtd;
}

void Produto::setPreco()
{
	string novoValor;
	cout << "Informe o novo preço para o produto: ";
            cin >> novoValor;
            while (!A.validNum(novoValor) && A.textToUpper(novoValor) != "R")
            {
                cout << "Valor inserido não é um número.\n";
                cout << "Informe o novo preço para o produto: ";
                cin >> novoValor;
            }
			if (A.textToUpper(novoValor) != "R")
			{
				preco=stof(novoValor);
			}
			else
			{
				return;
			}
}

string Produto::toString()
{
	return "| " + to_string(id) + "  |   " + nome + "   | " + to_string(quantidade) + "  |  " + to_string(preco) + "|";
}
