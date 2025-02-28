// #include "include/Pessoa.h"

// int main() {
//     Pessoa p("Harry Potter", 20);
//     Pessoa p1("Helom Valentim", 38);
//     p1.exibir();
//     return 0;
// }

#include "include/Loja.h"

#include <iostream>

using namespace std;

int main()
{
    Loja L;


    L.adicionarCliente("Helom", "1234", "Minha Casa");
    L.adicionarCliente("Fulano", "4321", "Casa dele");
    L.adicionarCliente("Ciclano", "1144", "Mora na rua");

    L.mostrarClientes();
}

/*
Para executar o código, utilize os seguintes comandos:
g++ -o main  Projeto_v2/src/Loja.cpp Projeto_v2/src/Cliente.cpp Projeto_v2/src/Auxiliares.cpp Projeto_v2/main.cpp -I include
./main

*/