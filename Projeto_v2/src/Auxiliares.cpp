#include "../include/Auxiliares.h"
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

void Auxiliares::showMenuClientes()
{
    char choice;
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MENU CLIENTES\033[0m\n";
        cout << endl;
        cout << "   C. CONSULTAR   " << "E. ELIMINAR   " << "A. ADICIONAR   " << "M. MODIFICAR   " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        // cout << endl;
        // printMatrix(mProd, linhasProd, colunasProd);
        // cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'C':
            cout << "Consultando Stock...\n";
            // showMenuSearchStock(mProd, linhasProd, colunasProd);
            break;
        case 'A':
            cout << "Adicionando Produto...\n";
            // showMenuAddProd(mProd, linhasProd, colunasProd);
            break;
        case 'E':
            cout << "Informe o ID do produto que deseja remover: ";
            // cin >> id;
            // linha = findItem(id, mProd, linhasProd, 0);
            // while (linha < 0 && textToUpper(id) != "R")
            // {
            //     cout << "O id inserido não foi encontrado.\n";
            //     cout << "Insira novamente o id : ";
            //     cin >> id;
            //     linha = findItem(id, mProd, linhasProd, 0);
            // }
            // if (textToUpper(id) == "R")
            // {
            //     choice = 'R';
            //     break;
            // }
            // getMatLineProd(mProd, mProduto, linha);
            cout << endl;
            cout << "\033[32m======================================================================================\n";
            // cout << "        Produto: \033[0m" << mProduto[0][1] << "  \033[32mQuantidade: \033[0m" << mProduto[0][2] <<"  \033[32mCusto: \033[0m" << mProduto[0][3] << "\n";
            cout << "\033[32m======================================================================================\033[0m\n";
            cout << endl;
            cout << "Deseja realmente remover o produto? (S/N): ";
            // cin >> id;
            // id = textToUpper(id);
            // if (id == "S")
            // {
            //     // diminuirLinhas(mProd, linhasProd, colunasProd, linha);
            // }
            break;
        case 'M':
            cout << "Escolha o ID: ";
            // cin >> id;
            // linha = findItem(id, mProd, linhasProd, 0);
            // while (linha < 0 && textToUpper(id) != "R")
            // {

            //     cout << "O id inserido não foi encontrado.\n";
            //     cout << "Insira novamente o id : ";
            //     cin >> id;
            //     linha = findItem(id, mProd, linhasProd, 0);
            //     // system("clear");
            // }
            // if (textToUpper(id) == "R")
            // {
            //     choice = 'R';
            //     break;
            // }

            // showMenuAltProd(mProd, linhasProd, id, linha);
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

void Auxiliares::showMenuStock(Loja L){
    char choice;
    do {
	system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MENU STOCK\033[0m\n";
        cout << endl;
        cout << "   M. MOSTRAR STOCK   " << "C. CRIAR PRODUTO   " << "A. ADICIONAR STOCK  " << "E. ELIMINAR" << "R. VOLTAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);
        
        switch (choice)
        {
        case 'M':
            L.mostrarProdutos();
            sleep(15);
            break;
        case 'C':
        
            break;
        
        case 'A':
            
            break;
        case 'E':

            break;
        
        default:
            break;
        }
    } while (choice != 'R');
    }

void Auxiliares::showMenuAddProdutos(){
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

    } while (choice != 'R');
}