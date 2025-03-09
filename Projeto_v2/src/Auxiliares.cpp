#include "../include/Auxiliares.h"
#include "../include/Cliente.h"
#include "../include/Loja.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale> // biblioteca para mudar charset para UTF-8
#include <cctype> //biblioteca para a função de validação std::isdigit(c)
#include <unistd.h>
#include <sstream>

Loja L;

string Auxiliares::textToUpper(string text)
{
    string retorno;
 
    for (char c : text)
    {
        retorno += toupper(c);
    }
    return retorno;
}

string Auxiliares::addZero(int num, int digitos)
{
    string numStr = to_string(num);
    while (numStr.size() < digitos)
    {
        numStr = string(digitos - numStr.size(), '0') + numStr;
    }
    return numStr;
}

string Auxiliares::arredondar(float num)
{
    stringstream stream;
    stream << fixed << setprecision(2) << num;
    return stream.str();
}

string Auxiliares::getDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string dateTime = addZero(ltm->tm_mday, 2) + "/" + addZero(1 + ltm->tm_mon, 2) + "/" + to_string(1900 + ltm->tm_year) + " " + addZero(ltm->tm_hour, 2) + ":" + addZero(ltm->tm_min, 2) + ":" + addZero(ltm->tm_sec, 2);
    return dateTime;
}

bool Auxiliares::validNum(string valor)
{ // funcao de validação de input

    for (char c : valor)
    {
        if (!isdigit(c) && c != '.') // verifica se o valor inserido é um número e aceita ponto.
        {
            return false;
        }
    }
    return true;
}

bool Auxiliares::sorteio(int nSorte, float minCompra, float valorCompra)
{
    string pontos = "";
    bool ganhou = false;
    int contador = 0;
    int qtdSorteios;

    if (valorCompra > minCompra)
    {
        qtdSorteios = valorCompra / minCompra;
    }
    else
    {
        cout << "Valor da compra não atingiu o mínimo para participar do sorteio.\n";
        sleep(3);
        return false;
    }

    do
    {
        string sorteio = to_string(rand() % 100 + 1);
        sorteio = addZero(stoi(sorteio), 3);

        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                   NÚMERO DA SORTE CLIENTE: \033[0m" << addZero(nSorte, 3) << "   \033[32mSORTEANDO" << pontos << "\n";
        cout << endl;
        // cout << "F. Finalizar venda   " << "N. NIF Cliente   "<<"C. Cancelar venda   " << "R. Retornar\n";
        cout << "======================================================================================\n";
        cout << endl;
        // cout << sorteio << "\n";
        cout << "                                 ------------- \n";
        cout << "                                 | \033[0m" << sorteio[0] << "\033[32m | \033[0m" << sorteio[1] << "\033[32m | \033[0m" << sorteio[2] << "\033[32m | \n";
        cout << "                                 ------------- \n";
        cout << endl;
        cout << "======================================================================================\033[0m\n";
        if (stoi(sorteio) == nSorte)
        {
            ganhou = true;
            cout << "                           PARABÉNS!!! VOCÊ GANHOU!!!\n";
            sleep(3);
            break;
        }
        else if (contador == qtdSorteios - 1)
        {
            cout << "                Infelizmente não foi desta vez! Boa sorte na próxima!\n";
            sleep(3);
            break;
        }

        if (pontos == "...")
        {
            pontos = "";
        }
        else
        {
            pontos += ".";
        }
        sleep(1);
        contador++;
    } while (!ganhou && contador < qtdSorteios);
    return ganhou;
}

// Funcoes para menus
void Auxiliares::showMenu()
{
    system("clear"); // Limpa o terminal no Windows
    cout << "\033[32m======================================================================================\n";
    cout << endl;
    cout << "                                   MENU PRINCIPAL\033[0m\n";
    cout << endl;
    cout << "    S. STOCK   " << "V. VENDAS   " << "C. CLIENTES   " << "R. RELATORIOS   "  << "F. FECHAR\n";
    cout << "\033[32m======================================================================================\n";
    cout << "                          Data e Hora: " << getDateTime() << "\n";
    cout << "======================================================================================\033[0m\n";
    cout << "Escolha uma opção: ";
}

void Auxiliares::showMenuClientes(Loja L2)
{
    char choice;
    L = L2;

    string id;
    int linha;
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MENU CLIENTES\033[0m\n";
        cout << endl;
        cout << "   C. CONSULTAR   " << "E. ELIMINAR   " << "A. ADICIONAR   " << "M. MODIFICAR   " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        L.mostrarClientes();
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'C':
            cout << "Consultando Cliente...\n";
            showMenuBuscaCliente(L);
            break;
        case 'A':
            cout << "Adicionando Cliente...\n";
            showMenuAddCliente(L);
            break;
        case 'E':
            cout << "Informe o ID do cliente que deseja remover: ";
            cin >> id;
            linha = L.buscarCliente("ID", id);
            while (linha < 0 && textToUpper(id) != "R")
            {
                cout << "O id inserido não foi encontrado.\n";
                cout << "Insira novamente o id : ";
                cin >> id;
                linha = L.buscarCliente("ID", id);
            }

            if (textToUpper(id) == "R")
            {
                choice = 'R';
                break;
            }

            cout << endl;
            cout << "\033[32m======================================================================================\n";
            cout << "        Nome: \033[0m" << L.ListaClientes[linha].getNome() << "  \033[32mTelefone: \033[0m" << L.ListaClientes[linha].getTelefone() <<"  \033[32mMorada: \033[0m" << L.ListaClientes[linha].getMorada() << "\n";
            cout << "\033[32m======================================================================================\033[0m\n";
            cout << endl;
            cout << "Deseja realmente remover o cliente? (S/N): ";
            cin >> choice;
            choice = toupper(choice);
            if (choice == 'S')
            {
                L.removerCliente(stoi(id));
            }
            break;
        case 'M':
            cout << "Escolha o ID: ";
            cin >> id;
            linha = L.buscarCliente("ID", id);
            while (linha < 0 && textToUpper(id) != "R")
            {
                cout << "O id inserido não foi encontrado.\n";
                cout << "Insira novamente o id : ";
                cin >> id;
                linha = L.buscarCliente("ID", id);
            }

            if (textToUpper(id) == "R")
            {
                choice = 'R';
                break;
            }

            showMenuAltCliente(stoi(id), L);
            break;
        case 'R':
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
            sleep(1);
        }
    } while (choice != 'R');
}

void Auxiliares::showMenuAltCliente(int id, Loja L2)
{
    char choice;
    L = L2;
    string novoValor;
    int pos = L.buscarCliente("ID", to_string(id));

    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MODIFICAR CLIENTE\033[0m\n";
        cout << endl;
        cout << "   N. ALTERAR NOME   " << "T. ALTERAR TELEFONE   " << "M. ALTERAR MORADA   " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        L.mostrarCliente(pos);
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
        case 'N':
            L.ListaClientes[pos].updateNome();
            break;
        case 'T':
            L.ListaClientes[pos].updateTelefone();
            break;
        case 'M':
            L.ListaClientes[pos].updateMorada();
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }

    } while (choice != 'R');
}

void Auxiliares::showMenuStock(Loja L){
    bool mostrarStock =false;
    char choice;
    string id;
    int linha;
    do {
	system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MENU STOCK\033[0m\n";
        cout << endl;
        cout << "  M. MOSTRAR STOCK   " << "C. CRIAR PRODUTO  " << " A. ALTERAR  " << " E. ELIMINAR  " << "  R. VOLTAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        if (mostrarStock)
        {
            L.mostrarProdutos();
        }
        
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);
        
        switch (choice)
        {
        case 'M':
        mostrarStock=true;
            break;
        case 'C':
            showMenuAddProdutos(L);
            break;
        
        case 'A':
            cout << "Digite o ID do produto desejado : ";
            cin >> id;
            linha = L.buscaProduto(stoi(id));
            while (linha < 0 && textToUpper(id) != "R")
            {
                cout << "O id inserido não foi encontrado.\n";
                cout << "Insira novamente o id : ";
                cin >> id;
                linha = L.buscaProduto(stoi(id));
            }
 
            if (textToUpper(id) == "R")
            {
                choice = 'R';
                break;
            }
            showMenuAltProd(L, stoi(id));
            break;
        case 'E':
        cout << "Informe o ID do produto que deseja remover: ";
        cin >> id;
        linha = L.buscaProduto(stoi(id));
        while (linha < 0 && textToUpper(id) != "R")
        {
            cout << "O id inserido não foi encontrado.\n";
            cout << "Insira novamente o id : ";
            cin >> id;
            linha = L.buscaProduto(stoi(id));
        }

        if (textToUpper(id) == "R")
        {
            choice = 'R';
            break;
        }

        cout << endl;
        cout << "\033[32m======================================================================================\n";
        cout << "        ID: \033[0m" << L.Stock[linha].getId() << "  \033[32mNome: \033[0m" << L.Stock[linha].getNome() <<"  \033[32mPreco: \033[0m" << L.Stock[linha].getPreco() << "\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        cout << "Deseja realmente remover o produto? (S/N): ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'S')
        {
            L.removeProduto(stoi(id));
        }
        break;
            break;
        
        default:
            break;
        }
    } while (choice != 'R');
    }

void Auxiliares::showMenuAddProdutos(Loja L){
    char choice;
    string id, nomeProd, qtdProd, precoProd;
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    ADICIONAR PRODUTO\033[0m\n";
        cout << endl;
        cout << "                                     R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
       L.mostrarProdutos();
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        id = to_string(L.getLastId() + 1);
        cout << "ID: " << id << endl;
        cout << "Insira nome do produto: ";
        cin.ignore();
        getline(cin, nomeProd);
        // cout <<"\n----------"<< nomeProd.size();
        nomeProd = textToUpper(nomeProd);
        if (nomeProd == "R")
        {
            choice = 'R';
            break;
        }
        cout << "Insira a quantidade: ";
        cin >> qtdProd;

        while (!validNum(qtdProd) && textToUpper(qtdProd) != "R")
        {
            cout << "Valor inserido não é um numero.\n";
            cout << "Insira a quantidade: ";
            cin >> qtdProd;
        }
        if (textToUpper(qtdProd) == "R")
        {
            choice = 'R';
            break;
        }

        cout << "Insira o custo: ";
        cin >> precoProd;
        while (!validNum(precoProd) && textToUpper(precoProd) != "R")
        {

            cout << "Valor inserido não é um numero.\n";
            cout << "Insira o custo: ";
            cin >> precoProd;
        }
        if (textToUpper(precoProd) == "R")
        {
            choice = 'R';
            break;
        }
        L.armazenaProduto(nomeProd, stoi(qtdProd), stof(precoProd));

    } while (choice != 'R');
}

void Auxiliares::showMenuAltProd(Loja L,int id)
{
    char choice;
    int linha;
    string novoValor;
    linha=L.buscaProduto(id);
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MODIFICAR PRODUTO\033[0m\n";
        cout << endl;
        cout << "   N. ALTERAR NOME   " << "Q. ALTERAR QUANTIDADE   " << "C. ALTERAR CUSTO  "<< "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        L.mostrarProdutos();
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
        case 'N':
            L.Stock[linha].setNome();
            break;
        case 'Q':
            L.Stock[linha].setQuantidade();
            break;
        case 'C':
            L.Stock[linha].setPreco();
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }

    } while (choice != 'R');
}

void Auxiliares::showMenuAddCliente(Loja L)
{
    char choice;
    string id, nome, telefone, morada;
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    ADICIONAR CLIENTE\033[0m\n";
        cout << endl;
        cout << "                                     R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        L.mostrarClientes();
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        id = to_string(L.getLastIdCliente() + 1);
        cout << "ID: " << id << endl;
        cout << "Insira o nome do cliente: ";
        cin.ignore();
        getline(cin, nome);
        // cout <<"\n----------"<< nomeProd.size();
        nome = textToUpper(nome);
        if (nome == "R")
        {
            choice = 'R';
            break;
        }
        cout << "Insira o Telefone: ";
        cin >> telefone;

        while (!validNum(telefone) && textToUpper(telefone) != "R")
        {
            cout << "Valor inserido não é um numero.\n";
            cout << "Insira o Telefone: ";
            cin >> telefone;
        }
        if (textToUpper(telefone) == "R")
        {
            choice = 'R';
            break;
        }

        cout << "Insira a morada: ";
        cin.ignore();
        getline(cin, morada);
        if (textToUpper(morada) == "R")
        {
            choice = 'R';
            break;
        }

        L.adicionarCliente(nome, telefone, morada);
    } while (choice != 'R');
}

void Auxiliares::showMenuBuscaCliente(Loja L)
{
    char choice;
    bool mostrarTabelaCompleta = false;
    string valor;
    int qtdLinhas = 0;
    int *vecLinha = new int[10];
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                   CONSULTAR CLIENTE\033[0m\n";
        cout << endl;
        cout << " I. PROC. POR ID " << "N. PROC. POR NOME " << "T. PROC. POR TELEFONE " << "M. MOSTRAR TODOS CLIENTES " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        if (qtdLinhas > 0 && !mostrarTabelaCompleta)
        {
            for (int i = 0; i < qtdLinhas; i++)
            {
                
                L.mostrarCliente(vecLinha[i]);
            }
        }
        if (mostrarTabelaCompleta)
        {
            L.mostrarClientes();
        }
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'M':
            mostrarTabelaCompleta = true;
            break;
        case 'I':
            cout << "Digite o ID do cliente desejado: ";
            cin.ignore();
            getline(cin, valor);
            qtdLinhas = L.buscarCliente("ID", valor);
            if (qtdLinhas < 0)
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
                break;
            }
            vecLinha[0] = qtdLinhas;
            mostrarTabelaCompleta = false;
            break;
        case 'N':
            cout << "Digite o nome do cliente desejado: ";
            cin.ignore();
            getline(cin, valor);
            valor = textToUpper(valor);
            vecLinha = L.buscarClientes("NOME", valor);
            qtdLinhas = L.qtdBuscarClientes("NOME", valor);
            if (qtdLinhas < 0)
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
                break;
            }
            mostrarTabelaCompleta = false;
            break;
        case 'T':
            cout << "Digite o telefone do cliente desejado: ";
            cin.ignore();
            getline(cin, valor);
            vecLinha = L.buscarClientes("TELEFONE", valor);
            qtdLinhas = L.qtdBuscarClientes("TELEFONE", valor);
            if (qtdLinhas < 0)
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
                break;
            }
            mostrarTabelaCompleta = false;
        case 'R':
            cout << "Retornando...\n";
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
            sleep(1);
        }
    } while (choice != 'R');
    delete[] vecLinha;
}

