#include "../include/Auxiliares.h"
#include "../include/Cliente.h"
#include "../include/Loja.h"
#include "../include/ProdCompra.h"
#include "../include/Vendas.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale> // biblioteca para mudar charset para UTF-8
#include <cctype> //biblioteca para a função de validação std::isdigit(c)
#include <unistd.h>
#include <sstream>

// Loja L;


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
    cout << "        S. STOCK   " << "V. VENDAS   " << "C. CLIENTES   " << "R. RELATÓRIOS   "  << "F. FECHAR\n";
    cout << "\033[32m======================================================================================\n";
    cout << "                          Data e Hora: " << getDateTime() << "\n";
    cout << "======================================================================================\033[0m\n";
    cout << "Escolha uma opção: ";
}

void Auxiliares::showMenuClientes(Loja &L)
{
    char choice;

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

void Auxiliares::showMenuAltCliente(int id, Loja &L)
{
    char choice;
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

void Auxiliares::showMenuStock(Loja &L){
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

void Auxiliares::showMenuAddProdutos(Loja &L){
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

void Auxiliares::showMenuAltProd(Loja &L,int id)
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
        // L.mostrarProdutos();
        L.Stock[linha].imprimirProduto(L.Stock[linha].tamanhoColunas());
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

void Auxiliares::showMenuAddCliente(Loja &L)
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

void Auxiliares::showMenuBuscaCliente(Loja &L)
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

void Auxiliares::showMenuNovaVenda(Loja &L)
{
    char opcao;
    float preco;
    bool retorno;
    string choice, qtdProd;
    int talao, linhaProd;
    float subTotal = 0.00;
    string dataHora = getDateTime();
    talao = L.getLastIdVendas() + 1;

    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                             NOVA VENDA - TALÃO: \033[0m" << talao << "\n";
        cout << endl;
        // cout << dataHora <<"                VALOR TOTAL A PAGAR: " << arredondar(subTotal) << "€ \n";
        cout << "     F. FINALIZAR VENDA   "<< " P. MOSTRAR PRODUTOS  " "  C. CANCELAR VENDA   " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        
            L.mostrarCarrinho();
        
        
        cout << "\033[32mData e Hora: " << dataHora << "                  VALOR TOTAL A PAGAR: " << arredondar(subTotal) << "€ \n";
        // cout << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Insira o ID do produto ou opção: ";
        cin >> choice;
        choice = textToUpper(choice);
        if (choice.length() > 0)
        {
            if (validNum(choice))
            {
                opcao = 'Z';
            }
            else
            {
                opcao = choice[0];
            }
        }
        switch (opcao)
        {
        case 'F':
            cout << "Finalizando venda...\n";
            retorno = showMenuFinalizarVenda(L, talao, dataHora, subTotal);
            if (retorno)
            {
                break;
            }

            return;
        case 'C':
            return;
            break;
        case 'P':
        showMenuStock(L);
            break;
        case 'Z':
        linhaProd = L.buscaProduto(stoi(choice));
            if (linhaProd < 0)
            {
                cout << "Produto não encontrado!!!\n";
                sleep(1);
                break;
            }
           // getMatLineProd(matStock, mProduto, linhaProd);
            cout << endl;
            cout << "\033[32m======================================================================================\n";
            cout << "                    Produto: \033[0m" << L.Stock[linhaProd].getNome() << "  \033[32mPreço: \033[0m" << arredondar(L.Stock[linhaProd].getPreco() * 1.30) << "€\n";
            cout << "\033[32m======================================================================================\033[0m\n";
            cout << endl;
            cout << "Informe a quantidade do produto: ";
            cin >> qtdProd;
            while (!validNum(qtdProd) && (textToUpper(qtdProd) != "R" || textToUpper(qtdProd) != "C"))
            {
                cout << "Valor inserido não é um número.\n";
                cout << "Informe a quantidade do produto: ";
                cin >> qtdProd;
            }
            while (qtdProd == "0" || stoi(qtdProd) > (L.Stock[linhaProd].getQuantidade()) && (textToUpper(qtdProd) != "R" || textToUpper(qtdProd) != "C"))
            {
                cout << "Quantidade inválida! Insira uma quantidade maior que 0 e menor que o stock atual do produto\n";
                cout << "Stock Atual do produto: " << L.Stock[linhaProd].getQuantidade() << "\n";
                cout << "Informe a quantidade do produto: ";
                cin >> qtdProd;
            }
            if (textToUpper(qtdProd) == "R")
            {
                break;
            }
            if (textToUpper(qtdProd) == "C")
            {
                return;
            }
            // listaCarrinho[contCarrinho] = Carrinho(L.Stock[linhaProd].getId(),L.Stock[linhaProd].getNome(),stoi(qtdProd),preco, preco * 1.30, (preco * 1.30) * stoi(qtdProd));
            // contCarrinho++;
            L.addProdCarrinho(L.Stock[linhaProd].getId(),L.Stock[linhaProd].getNome(),stoi(qtdProd),L.Stock[linhaProd].getPreco());
            subTotal=L.calcSubTotal();
            break;
        default:
            if (opcao != 'R')
            {
                cout << "Opção inválida! Tente novamente.\n";
                sleep(1);
            }
        }

    } while (opcao != 'R');
}

bool Auxiliares::showMenuFinalizarVenda(Loja &L, int talao, string dataHora, float subTotal)
{
    int nSorte, step = 0;
    char opcao = 'Z';
    string clienteId, clienteNome = "", entrada = "";
    bool ganhou = false, sair = false, sorteado = false;
    float valorPago = 0.00, troco = 0.00;

    nSorte = talao;

    do
    {
    reexibir:
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                          FINALIZAR VENDA - ID VENDA: \033[0m" << talao << "\n";
        cout << endl;
        cout << "              C. CANCELAR VENDA   " << "V. VOLTAR ETAPA   " << "R. RETORNAR A VENDA\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        L.mostrarCarrinho();
        cout << endl;
        cout << "\033[32m======================================================================================\n";
        cout << "                 Talão: \033[0m" << talao << "  \033[32mData e Hora: \033[0m" << dataHora << " \n";
        if (!clienteNome.empty())
        {
            cout << "\033[32mNome Cliente: \033[0m" << clienteNome << "                  \033[32mNúmero da Sorte: \033[0m" << addZero(nSorte, 3) << "\n";
        }
        cout << "\033[32mTotal a pagar: \033[0m" << arredondar(subTotal) << "€ \n";
        cout << "\033[32mValor pago: \033[0m" << arredondar(valorPago) << "€ \n";
        cout << "\033[32mTroco: \033[0m" << arredondar(troco) << "€ \n";
        cout << "\033[32m======================================================================================\033[0m\n";
        opcao = 'Z';
        if (step == 0)
        {
            cout << "Insira o ID do cliente ou N para não adicionar cliente: ";
        }
        else if (step == 1)
        {
            cout << "Deseja participar do sorteio? (S/N): ";
            cin >> entrada;
            entrada = textToUpper(entrada);
            if (entrada == "S")
            {
                ganhou = sorteio(nSorte, 5.00, subTotal);
                if (ganhou)
                {
                    cout << "Sua compra será grátis desta vez! Parabéns\n";
                    step = 3;
                    sorteado = true;
                    goto reexibir;
                }
                else
                {
                    step = 2;
                    sorteado = true;
                    opcao = 'Z';
                    goto reexibir;
                }
            }
            else
            {
                step = 2;
                goto reexibir;
            }
        }
        if (step == 2)
        {
            cout << "Insira o valor pago pelo cliente ou opção: ";
        }
        if (step == 3)
        {
            goto finalizar;
        }

        cin >> entrada;
        entrada = textToUpper(entrada);

        if (entrada == "R" || entrada == "V" || entrada == "C" || entrada == "N")
        {
            opcao = entrada[0];
        }
        else if (!validNum(entrada) && entrada.length() > 0)
        {
            opcao = 'S';
        }

        switch (opcao)
        {
        case 'Z':
            if (step == 0 && entrada != "N")
            {
                int linhaCliente = L.buscarCliente("ID", entrada);
                if (linhaCliente >= 0)
                {
                    clienteId = entrada;
                    clienteNome = L.ListaClientes[linhaCliente].getNome();
                    step = 1;
                }
                else
                {
                    cout << "Cliente não encontrado! Insira um ID válido ou N para não adicionar cliente.\n";
                    sleep(1);
                }
            }
            else if (step == 0 && entrada == "N")
            {
                step = 1;
            }
            if (step == 2)
            {
                valorPago = stof(entrada);
                while (valorPago < subTotal && entrada != "C" && entrada != "R" && entrada != "V")
                {
                    cout << "Valor pago é inferior ao total a pagar. Insira um valor igual ou superior ao total a pagar.\n";
                    cout << "Insira o valor pago pelo cliente ou opção: ";
                    cin >> entrada;
                    entrada = textToUpper(entrada);
                    while (!validNum(entrada) && entrada != "C" && entrada != "R" && entrada != "V")
                    {
                        cout << "Valor inserido não é um número.\n";
                        cout << "Insira o valor pago pelo cliente ou opção: ";
                        cin >> entrada;
                        entrada = textToUpper(entrada);
                    }
                    valorPago = stof(entrada);
                    if (entrada == "C" || entrada == "R" || entrada == "V")
                    {
                        break;
                    }
                }
                if (entrada == "C" || entrada == "R" || entrada == "V")
                {
                    opcao = entrada[0];
                    goto finalizar;
                }
                troco = valorPago - subTotal;
                step = 3;
                goto reexibir;
            }
        finalizar:
            if (step == 3)
            {
                L.addProdCompra(talao);
                L.finalizarVenda(talao, dataHora,subTotal, clienteNome );
                cout << "      Compra finalizada com sucesso! Obrigado pela preferência e volte sempre\n";
                sleep(5);
                return false;
            }

            break;
        case 'V':
            if (step > 0)
            {
                if (step == 2)
                {
                    step = 0;
                }
                else
                {
                    step--;
                }
            }
            else
            {
                cout << "Não é possível voltar mais etapas.\n";
                sleep(1);
            }

            break;
        case 'C':
            cout << "Cancelando venda...\n";
            sleep(1);
            sair = true;
            return false;
            break;
        case 'N':
            cout << "Cliente não informado.\n";
            sleep(1);
            step = 2;
            break;
        case 'R':
            cout << "Retornando a venda...\n";
            sleep(1);
            sair = false;
            return true;
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
            sleep(2);
        }
    } while (!sair);
    return false;
}

void Auxiliares::showMenuRelatorioVendas(Loja &L)
{
    char choice;
    string nomeProd;
    bool relVendas = false;
    bool relVendasProd = false;
    bool relStock = false;

    do
    {
        system("clear"); // Limpa o terminal no Windows
        cout << "\033[32m======================================================================================\n";
        cout << endl;
        cout << "                                    RELATÓRIO DE VENDAS\033[0m\n";
        cout << endl;
        cout << "     P. REL. POR PRODUTO    " << "G. REL. GERAL DE VENDAS    " << "S. REL. STOCK    " << "R. RETORNAR\n";
        cout << "\033[32m======================================================================================\033[0m\n";
        cout << endl;
        if (relVendas)
        {
            L.impRelVendas();
        }
        if (relVendasProd)
        {
            L.impRelVendasProd(nomeProd);
        }
        if (relStock)
        {
            L.mostrarProdutos();
        }
        cout << endl;
        cout << "                          \033[32mData e Hora: " << getDateTime() << "\n";
        cout << "======================================================================================\033[0m\n";
        cout << "Escolha uma opção: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'P':
            cout << "Informe o nome do Produto: ";
            cin.ignore();
            getline(cin, nomeProd);
            nomeProd = textToUpper(nomeProd);
            relVendas = false;
            relVendasProd = true;
            relStock = false;
            break;
        case 'G':
            relVendas = true;
            relVendasProd = false;
            relStock = false;
            break;
        case 'S':
            relVendas = false;
            relVendasProd = false;
            relStock = true;
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (choice != 'R');
}
