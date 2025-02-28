#include "include/Loja.h"
#include "include/Auxiliares.h"
#include <iostream>
#include <locale> // biblioteca para mudar charset para UTF-8

using namespace std;

int main()
{
    setlocale(LC_ALL, ""); // mudar charset para utf-8
    system("color A");     // Mudar cor do terminal no Windows
    char choice;
    Loja L;
    Auxiliares A;

    do
    {
        A.showMenu();
        cin >> choice;
        choice = toupper(choice);
    } while (choice != 'F');
    

    // L.adicionarCliente("Helom", "1234", "Minha Casa");
    // L.adicionarCliente("Fulano", "4321", "Casa dele");
    // L.adicionarCliente("Ciclano", "1144", "Mora na rua");

    // L.mostrarClientes();

    // cout << A.textToUpper("HELLO word") << endl;
}

/*
Para executar o código, utilize os seguintes comandos:
g++ -o main  Projeto_v2/src/Loja.cpp Projeto_v2/src/Cliente.cpp Projeto_v2/src/Auxiliares.cpp Projeto_v2/main.cpp -I include
./main

*/