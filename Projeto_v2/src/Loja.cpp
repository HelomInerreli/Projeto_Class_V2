#include "../include/Loja.h"
#include "../include/Auxiliares.h"
#include <iostream>
#include <string>

using namespace std;

Loja::Loja()
{

}
Loja::Loja(Loja &L)
{
    contCliente = L.contCliente;
    for (int i = 0; i < contCliente; i++)
    {
        ListaClientes[i] = L.ListaClientes[i];
    }

    contProduto = L.contProduto;
    for (int i = 0; i < contProduto; i++)
    {
        Stock[i] = L.Stock[i];
    }
}

//Cliente -------------------------------------------------------------------------------
void Loja::adicionarCliente(string nome, string telefone, string morada)
{
    int retID = getLastIdCliente() + 1;

    if (contCliente < 100)
    {
        ListaClientes[contCliente] = Cliente(retID, nome, telefone, morada);
        contCliente++;
    }
    else
    {
        cout << "Lista de clientes cheia...";
    }

}

void Loja::removerCliente(int id)
{
    int pos = buscarCliente("ID", to_string(id));

    for (pos; pos < contCliente -1; pos++)
    {
        ListaClientes[pos] = ListaClientes[pos + 1];
    }
    contCliente--;
}

void Loja::mostrarCliente(int pos)
{
    int* tamanhos = tamanhosColunasClientes();
    int tLinhas = tamanhos[0] + tamanhos[1] + tamanhos[2] + tamanhos[3] + 16;
    string txtTitulo = " LISTA DE CLIENTES ";
    int tTitulo = (tLinhas - txtTitulo.length()) / 2;
    string linha = "";
    for (int i = 0; i < tLinhas; i++)
    {
        linha += "-";
    }
    string linhaDupla = "";
    for (int i = 0; i < tTitulo; i++)
    {
        linhaDupla += "=";
    }
    string cabecalho = "| ID";
    for (int i = 0; i < tamanhos[0] - 2; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | NOME ";
    for (int i = 0; i < tamanhos[1] - 4; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | TELEFONE";
    for (int i = 0; i < tamanhos[2] - 7; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | MORADA";
    for (int i = 0; i < tamanhos[3] - 6; i++)
    {
        cabecalho += " ";
    }
    cabecalho += "  |";

    cout << endl;
    cout << linha << "\n";
    cout << linhaDupla << txtTitulo << linhaDupla << "\n";
    cout << linha << "\n";
    cout << cabecalho << "\n";
    cout << linha << "\n";


    ListaClientes[pos].imprimirCliente(tamanhos);

    cout << linha << "\n";
    cout << endl;
}

void Loja::mostrarClientes()
{
    int* tamanhos = tamanhosColunasClientes();
    int tLinhas = tamanhos[0] + tamanhos[1] + tamanhos[2] + tamanhos[3] + 16;
    string txtTitulo = " LISTA DE CLIENTES ";
    int tTitulo = (tLinhas - txtTitulo.length()) / 2;
    string linha = "";
    for (int i = 0; i < tLinhas; i++)
    {
        linha += "-";
    }
    string linhaDupla = "";
    for (int i = 0; i < tTitulo; i++)
    {
        linhaDupla += "=";
    }
    string cabecalho = "| ID";
    for (int i = 0; i < tamanhos[0] - 2; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | NOME ";
    for (int i = 0; i < tamanhos[1] - 4; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | TELEFONE";
    for (int i = 0; i < tamanhos[2] - 7; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | MORADA";
    for (int i = 0; i < tamanhos[3] - 6; i++)
    {
        cabecalho += " ";
    }
    cabecalho += "  |";

    cout << endl;
    cout << linha << "\n";
    cout << linhaDupla << txtTitulo << linhaDupla << "\n";
    cout << linha << "\n";
    cout << cabecalho << "\n";
    cout << linha << "\n";

    for (int i = 0; i < contCliente; i++)
    {
        ListaClientes[i].imprimirCliente(tamanhos);
    }
    cout << linha << "\n";
    cout << endl;
}

int Loja::getLastIdCliente()
{
    int maiorId = 0;

    for (int i = 0; i < contCliente; i++)
    {
        int id = ListaClientes[i].getId();
        if ( id > maiorId)
        {
            maiorId = id;
        }
    }
    return maiorId;
}

int Loja::buscarCliente(string campo, string valor)
{
    if (campo == "ID")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getId() == stoi(valor))
            {
                return i;
            }	
        }
    } else if (campo == "NOME")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getNome() == valor)
            {
                return i;
            }
        }
    } else if (campo == "TELEFONE")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getTelefone() == valor)
            {
                return i;
            }
        }
    } else if (campo == "MORADA")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getMorada() == valor)
            {
                return i;
            }
        }
    } 

    return -1;
}

int* Loja::buscarClientes(string campo, string valor)
{
    int* ids = new int[100];
    int cont = 0;

    if (campo == "ID")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getId() == stoi(valor))
            {
                ids[cont] = i;
                cont++;
            }	
        }
    } else if (campo == "NOME")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getNome() == valor)
            {
                ids[cont] = i;
                cont++;
            }
        }
    } else if (campo == "TELEFONE")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getTelefone() == valor)
            {
                ids[cont] = i;
                cont++;
            }
        }
    } else if (campo == "MORADA")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getMorada() == valor)
            {
                ids[cont] = i;
                cont++;
            }
        }
    } 
    ids[cont] = -1;
    return ids;
}

int Loja::qtdBuscarClientes(string campo, string valor)
{
    int cont = 0;

    if (campo == "ID")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getId() == stoi(valor))
            {
                cont++;
            }	
        }
    } else if (campo == "NOME")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getNome() == valor)
            {
                cont++;
            }
        }
    } else if (campo == "TELEFONE")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getTelefone() == valor)
            {
                cont++;
            }
        }
    } else if (campo == "MORADA")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getMorada() == valor)
            {
                cont++;
            }
        }
    } 
    return cont;
}

int* Loja::tamanhosColunasClientes()
{
    int* tamanhos = new int[4];
    tamanhos[0] = 0;
    tamanhos[1] = 0;
    tamanhos[2] = 0;
    tamanhos[3] = 0;

    for (int i = 0; i < contCliente; i++)
    {
        int* tamanhosCliente = ListaClientes[i].tamanhoColunas();
        for (int j = 0; j < 4; j++)
        {
            if (tamanhosCliente[j] > tamanhos[j])
            {
                tamanhos[j] = tamanhosCliente[j];
            }
        }
    }

    return tamanhos;
}

//Produto -------------------------------------------------------------------------------
void Loja::mostrarProdutos()
{
    int* tamanhos = tamanhoColunasProdutos();
    int tLinhas = tamanhos[0] + tamanhos[1] + tamanhos[2] + tamanhos[3] + 16;
    string txtTitulo = " LISTA DE PRODUTOS ";
    int tTitulo = (tLinhas - txtTitulo.length()) / 2;
    string linha = "";
    for (int i = 0; i < tLinhas; i++)
    {
        linha += "-";
    }
    string linhaDupla = "";
    for (int i = 0; i < tTitulo; i++)
    {
        linhaDupla += "=";
    }
    string cabecalho = "| ID";
    for (int i = 0; i < tamanhos[0] - 2; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | NOME ";
    for (int i = 0; i < tamanhos[1] - 4; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | QTD ";
    for (int i = 0; i < tamanhos[2] - 3; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | PRECO ";
    for (int i = 0; i < tamanhos[3] - 6; i++)
    {
        cabecalho += " ";
    }
    cabecalho += "|";

    cout << endl;
    cout << linha << "\n";
    cout << linhaDupla << txtTitulo << linhaDupla << "\n";
    cout << linha << "\n";
    cout << cabecalho << "\n";
    cout << linha << "\n";

    for (int i = 0; i < contProduto; i++)
    {
        Stock[i].imprimirProduto(tamanhos);
    }
    cout << linha << "\n";
    cout << endl;
}

void Loja::armazenaProduto(string nome, int quantidade, float preco)
{	
    int lastID = getLastId() + 1;
    if (contProduto < 100)
    {
        Stock[contProduto] = Produto(lastID, nome, quantidade, preco);
        contProduto++;
    }
    else
    {
        cout << "Stock cheio!";
    }
}

int Loja::buscaProduto(int id)
{
    for (int i = 0; i < contProduto; i++)
    {
        if (Stock[i].getId() == id)
        {
            return i;
        }
    
    }
    return -1;
}

void Loja::imprimeProduto(int i)
{
    cout << "[======================================================================================\n";
    cout << endl;
    cout << "                                    PRODUTO\n";
    cout << endl;
    cout << "[======================================================================================\n";
    cout << "| ID | DESCRICAO | QTD | PRECO |\n";
    cout << "________________________________\n";
    cout << Stock[i].toString() << endl << endl;
}

void Loja::removeProduto(int id)
{
    int pos = buscaProduto(id);

    for (pos; pos < contProduto -1; pos++)
    {
        Stock[pos] = Stock[pos + 1];
    }
    contProduto--;
}

int Loja::getLastId()
{
    int maiorID = 0;

    for (int i = 0; i < contProduto; i++)
    {
        int id = Stock[i].getId();
        if ( id > maiorID)
        {
            maiorID = id;
        }


    }
    return maiorID;
}

// Implementação da função tamanhoColunasProdutos
int* Loja::tamanhoColunasProdutos()
{
    int* tamanhos = new int[4];
    tamanhos[0] = 0;
    tamanhos[1] = 0;
    tamanhos[2] = 0;
    tamanhos[3] = 0;

    for (int i = 0; i < contProduto; i++)
    {
        int* tamanhosProduto = Stock[i].tamanhoColunas();
        for (int j = 0; j < 4; j++)
        {
            if (tamanhosProduto[j] > tamanhos[j])
            {
                tamanhos[j] = tamanhosProduto[j];
            }
        }
    }

    return tamanhos;
}

//Vendas -----------------------------------------------------------------------------------

//Relatorios -------------------------------------------------------------------------------

//Auxiliares -------------------------------------------------------------------------------
void Loja::preencherDadosIniciais()
{
    //Clientes
    ListaClientes[0] = Cliente(10, "Joao", "123456789", "Rua 1");
    ListaClientes[1] = Cliente(23, "Maria", "987654321", "Rua 2");
    ListaClientes[2] = Cliente(03, "Jose", "123456789", "Rua 3");
    ListaClientes[3] = Cliente(04, "Ana", "987654321", "Rua 4");
    ListaClientes[4] = Cliente(05, "Pedro", "123456789", "Rua 522222222");
    contCliente = 5;

    //Produtos
    Stock[0] = Produto(1, "Produto 1", 10, 10.5);
    Stock[1] = Produto(2, "Produto 2", 20, 20.5);
    Stock[2] = Produto(3, "Produto 3", 30, 30.5);
    Stock[3] = Produto(4, "Produto 4", 40, 40.5);
    Stock[4] = Produto(5, "Produto 5", 50, 50.5);
    contProduto = 5;
}