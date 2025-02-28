#include "../include/Pessoa.h"
#include <iostream>

Pessoa::Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {}

void Pessoa::exibir() const {
    std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
}
