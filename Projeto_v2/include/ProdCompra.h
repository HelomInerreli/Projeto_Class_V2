#pragma once

#include <string>

using namespace std;

class ProdCompra
{
private:
    int talao;
    int idProd;
    string descProd;
    int qtd;
    float preco;

public:
    ProdCompra();
    ProdCompra(int talao, int idProd, string descProd, int qtd, float preco);
    
    void imprimirProdCompra(int* tamanhos);
    string getDescProd();
    int getQtd();
    float getPreco();
    int getTalao();
    int* tamanhoColunas();
};
