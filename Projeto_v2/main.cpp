#include "include/Loja.h"
#include "include/Auxiliares.h"
#include <iostream>
#include <locale> // biblioteca para mudar charset para UTF-8
#include <unistd.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // mudar charset para utf-8
    char choice;
    Loja L;
    Auxiliares A;

    L.preencherDadosIniciais();
    
    do
    {
        A.showMenu();
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'S':
            cout << "Opção Stock\n";
            A.showMenuStock(L);            break;
        case 'V':
            cout << "Opção Vendas\n";
            A.showMenuVendas(L);
            break;
        case 'C':
            cout << "Opção Clientes\n";
            A.showMenuClientes(L);
            break;
        case 'R':
            cout << "Opção Relatorios\n";
            break;
        case 'F':
            cout << "Opção Fechar\n";
            break;
        default:
            cout << "Opção inválida\n";
            break;
        }
    } while (choice != 'F');
    
}

/*
Para executar o código, utilize os seguintes comandos:
g++ -o main  Projeto_v2/src/Loja.cpp Projeto_v2/src/Cliente.cpp Projeto_v2/src/Relatorio.cpp Projeto_v2/src/Produto.cpp Projeto_v2/src/Auxiliares.cpp Projeto_v2/main.cpp -I include
./main

*/