#include "../include/Auxiliares.h"
#include "../include/Cliente.h"
#include "../include/Loja.h"
#include "../include/Vendas.h"
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
        L.mostrarCliente(pos, true);
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
    int *vecLinha = nullptr; // Inicializa como nullptr para evitar problemas
    do
    {
        system("clear"); // Limpa o terminal no Linux
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                   CONSULTAR CLIENTE\033[0m\n";
        cout << endl;
        cout << " I. PROC. ID    " << "N. PROC. NOME    " << "T. PROC. TELEFONE    " << "M. TODOS CLIENTES    " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        if (qtdLinhas > 0 && !mostrarTabelaCompleta)
        {
            cout << "Clientes encontrados: " << qtdLinhas << endl;
            for (int i = 0; i < qtdLinhas; i++)
            {
                bool showHeader = i == 0;
                L.mostrarCliente(vecLinha[i], showHeader);
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
            qtdLinhas = L.qtdBuscarClientes("ID", valor);
            if (qtdLinhas > 0)
            {
                delete[] vecLinha; // Libera memória anterior, se houver
                vecLinha = L.buscarClientes("ID", valor);
                mostrarTabelaCompleta = false;
            }
            else
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
            }
            break;
            case 'N':
            cout << "Digite o nome do cliente desejado: ";
            cin.ignore(); // Limpa o buffer de entrada
            getline(cin, valor);
            // valor = textToUpper(valor); // Converte o valor para maiúsculas
            qtdLinhas = L.qtdBuscarClientes("NOME", valor); // Busca a quantidade de clientes
            if (qtdLinhas > 0)
            {
                delete[] vecLinha; // Libera memória anterior, se houver
                vecLinha = L.buscarClientes("NOME", valor); // Busca os índices dos clientes
                mostrarTabelaCompleta = false;
            }
            else
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
            }
            break;
        case 'T':
            cout << "Digite o telefone do cliente desejado: ";
            cin.ignore();
            getline(cin, valor);
            qtdLinhas = L.qtdBuscarClientes("TELEFONE", valor);
            if (qtdLinhas > 0)
            {
                delete[] vecLinha; // Libera memória anterior, se houver
                vecLinha = L.buscarClientes("TELEFONE", valor);
                mostrarTabelaCompleta = false;
            }
            else
            {
                cout << "Cliente não encontrado!!!\n";
                sleep(1);
            }
            break;
        case 'R':
            cout << "Retornando...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
            sleep(1);
        }
    } while (choice != 'R');
    delete[] vecLinha; // Libera memória alocada antes de sair
}


void Auxiliares::showMenuVendas(Loja L)
{
    char choice;
    bool mostrarVendas = false;
    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    MENU DE VENDAS\033[0m\n";
        cout << endl;
        cout << "               V.VENDER   " << "C. CONSULTAR PRODUTOS DE UMA VENDA  " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        if (mostrarVendas)
        {
            L.mostrarVendas();
        }
        ;
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'V':
            cout << "Vender...\n";
            mostrarVendas=true;
            break;
        case 'C':
            cout << "Consultando Produtos...\n";
            //showMenuConsultaProdutosVendas(matProdVendas, linhasProdVendas, mat, linhas);
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (choice != 'R');
}

// void Auxiliares::showMenuNovaVenda(Loja L)
// {
//     char opcao;
//     bool retorno;
//     string choice, qtdProd;
//     int talao, linhaProd;
//     int linhasCarr = 1;
//     float subTotal = 0.00;
//     string dataHora = getDateTime();
//     talao = findLastId(matVenda, linhasMatVenda) + 1;
//     string **mProduto = new string *[1];
//     mProduto[0] = new string[4];
//     string **mCarrinho = new string *[1]; // criar matriz para buscar produtos do id solicitado (na modificação de produto)
//     for (int i = 0; i < linhasCarr; i++)
//     {
//         mCarrinho[i] = new string[6];
//     }
//     mCarrinho[0][0] = "ID PROD";
//     mCarrinho[0][1] = "DESCRICAO DO PRODUTO";
//     mCarrinho[0][2] = "QTD PROD";
//     mCarrinho[0][3] = "VALOR";
//     mCarrinho[0][4] = "VALOR + IVA";
//     mCarrinho[0][5] = "VALOR TOTAL";

//     do
//     {
//         system("clear"); // Limpa o terminal no Windows
//         cout << "\033[32m======================================================================================\n";
//         cout << endl;
//         cout << "                             NOVA VENDA - TALÃO: \033[0m" << talao << "\n";
//         cout << endl;
//         // cout << dataHora <<"                VALOR TOTAL A PAGAR: " << arredondar(subTotal) << "€ \n";
//         cout << "     F. FINALIZAR VENDA   " << "P. CONSULTAR PRODUTO   " << "C. CANCELAR VENDA   " << "R. RETORNAR\n";
//         cout << "\033[32m======================================================================================\033[0m\n";
//         L.mostrarProdutos();
//         cout << endl;
//         cout << "\033[32mData e Hora: " << dataHora << "                  VALOR TOTAL A PAGAR: " << arredondar(subTotal) << "€ \n";
//         // cout << getDateTime() << "\n";
//         cout << "======================================================================================\033[0m\n";
//         cout << "Insira o ID do produto ou opção: ";
//         cin >> choice;
//         choice = textToUpper(choice);
//         if (choice.length() > 0)
//         {
//             if (validNum(choice))
//             {
//                 opcao = 'Z';
//             }
//             else
//             {
//                 opcao = choice[0];
//             }
//         }

//         switch (opcao)
//         {
//         case 'P':
//             showMenuSearchStock(matStock, linhasMatStock, 4);
//             break;
//         case 'F':
//             cout << "Finalizando venda...\n";
//             retorno = showMenuFinalizarVenda(matVenda, linhasMatVenda, matProdVendas, linhasMatProdVendas, mCarrinho, linhasCarr, matStock, linhasMatStock, talao, subTotal, dataHora);
//             if (retorno)
//             {
//                 break;
//             }

//             return;
//         case 'C':
//             return;
//             break;
//         case 'Z':
//             linhaProd = findItem(choice, matStock, linhasMatStock, 0);
//             if (linhaProd < 0)
//             {
//                 cout << "Produto não encontrado!!!\n";
//                 sleep(1);
//                 break;
//             }
//             getMatLineProd(matStock, mProduto, linhaProd);
//             cout << endl;
//             cout << "\033[32m======================================================================================\n";
//             cout << "                    Produto: \033[0m" << mProduto[0][1] << "  \033[32mPreço: \033[0m" << arredondar(stof(mProduto[0][3]) * 1.30) << "€\n";
//             cout << "\033[32m======================================================================================\033[0m\n";
//             cout << endl;
//             cout << "Informe a quantidade do produto: ";
//             cin >> qtdProd;
//             while (!validNum(qtdProd) && (textToUpper(qtdProd) != "R" || textToUpper(qtdProd) != "C"))
//             {
//                 cout << "Valor inserido não é um número.\n";
//                 cout << "Informe a quantidade do produto: ";
//                 cin >> qtdProd;
//             }
//             while (qtdProd == "0" || stoi(qtdProd) > stoi(mProduto[0][2]) && (textToUpper(qtdProd) != "R" || textToUpper(qtdProd) != "C"))
//             {
//                 cout << "Quantidade inválida! Insira uma quantidade maior que 0 e menor que o stock atual do produto\n";
//                 cout << "Stock Atual do produto: " << mProduto[0][2] << "\n";
//                 cout << "Informe a quantidade do produto: ";
//                 cin >> qtdProd;
//             }
//             if (textToUpper(qtdProd) == "R")
//             {
//                 break;
//             }
//             if (textToUpper(qtdProd) == "C")
//             {
//                 return;
//             }

//             inserirProdutoVenda(choice, stoi(qtdProd), mCarrinho, linhasCarr, matStock, linhasMatStock, linhaProd);
//             subTotal = calcSubTotal(mCarrinho, linhasCarr);
//             break;
//         default:
//             if (opcao != 'R')
//             {
//                 cout << "Opção inválida! Tente novamente.\n";
//                 sleep(1);
//             }
//         }

//     } while (opcao != 'R');
// }