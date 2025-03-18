#include "../include/ProdCompra.h"
#include "../include/Auxiliares.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

Auxiliares auxCp;

ProdCompra::ProdCompra()
{
}

ProdCompra::ProdCompra(int talao, int idProd, string descProd, int qtd, float preco)
{
    this->talao = talao;
    this->idProd = idProd;
    this->descProd = descProd;
    this->qtd = qtd;
    this->preco = preco;
}

int* ProdCompra::tamanhoColunas()
{
    int* tamanhos = new int[5];
    tamanhos[0] = to_string(talao).length();
    tamanhos[1] = to_string(idProd).length();
    tamanhos[2] = descProd.length();
    tamanhos[3] = to_string(qtd).length();
    tamanhos[4] = auxCp.arredondar(preco).length();

    tamanhos[4] = (tamanhos[4] < 6) ? 6 : tamanhos[4];

    // cout << "Tamanhos: " << tamanhos[0] << " " << tamanhos[1] << " " << tamanhos[2] << " " << tamanhos[3] << " " << tamanhos[4] << endl;
    // sleep(10);
    return tamanhos;
}

void ProdCompra::imprimirProdCompra(int* tamanhos)
{
    string linha = "";
    cout << linha << "\n";
    // cout << "| " << auxCp.addZero(talao, 2) << " | " << auxCp.addZero(idProd, 2) << " | " << descProd;
    cout << "| " << auxCp.addZero(talao, 2) ;
    for (int i = 0; i <= tamanhos[0]; i++)
    {
        cout << " ";
    }
    cout << " | " << auxCp.addZero(idProd, 2) ;
    for (int i = 0; i <= tamanhos[1]; i++)
    {
        cout << " ";
    }
    cout << " | " << descProd;

    for (int i = 0; i <= tamanhos[2] - descProd.length(); i++)
    {
        cout << " ";
    }
    cout << " | " << auxCp.addZero(qtd, 2) ;
    for (int i = 0; i < tamanhos[3] - to_string(qtd).length(); i++)
    {
        cout << " ";
    }
    cout << " | " << auxCp.arredondar(preco) ;
    for (int i = 0; i < tamanhos[4] - auxCp.arredondar(preco).length(); i++)
    {
        cout << " ";
    }
    cout << " |";
    cout << linha << "\n";
}

string ProdCompra::getDescProd()
{
    return descProd;
}

int ProdCompra::getQtd()
{
    return qtd;
}

float ProdCompra::getPreco()
{
    return preco;
}

int ProdCompra::getTalao()
{
    return talao;
}