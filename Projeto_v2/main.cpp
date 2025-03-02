#include "include/Loja.h"
#include "include/Auxiliares.h"
#include <iostream>
#include <locale> // biblioteca para mudar charset para UTF-8

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // mudar charset para utf-8
    char choice;
    Loja L;
    Auxiliares A;

    do
    {
        A.showMenu();
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'S':
            cout << "Opção Stock\n";
            break;
        case 'V':
            cout << "Opção Vendas\n";
            break;
        case 'A':
            cout << "Opção Sorteio Aleatório\n";
            A.sorteio(123, 5, 50);
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