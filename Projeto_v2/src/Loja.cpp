#include "../include/Loja.h"
#include "../include/Auxiliares.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

Auxiliares auxL;

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

    contProdCompra = L.contProdCompra;
    for (int i = 0; i < contProdCompra; i++)
    {
        ListaProdCompra[i] = L.ListaProdCompra[i];
    contVendas = L.contVendas;
    for (int i = 0; i < contVendas; i++)
    {
        ListaVendas[i]=L.ListaVendas[i];
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

void Loja::mostrarCliente(int pos, bool showHeader)
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

    if (showHeader)
    {
        cout << endl;
        cout << linha << "\n";
        cout << linhaDupla << txtTitulo << linhaDupla << "\n";
        cout << linha << "\n";
        cout << cabecalho << "\n";
        cout << linha << "\n";
    }
    
    // cout << endl;
    // cout << linha << "\n";
    // cout << linhaDupla << txtTitulo << linhaDupla << "\n";
    // cout << linha << "\n";
    // cout << cabecalho << "\n";
    // cout << linha << "\n";


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
    string retorno = "";
    if (campo == "ID")
    {
        for (int i = 0; i < contCliente; i++)
        {
            if (ListaClientes[i].getId() == stoi(valor))
            {
                // cout << i << " - Cliente encontrado!\n";
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
    for (int i = 0; i < tamanhos[3] - 5; i++)
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
int* Loja::tamanhoColunasVendas()
{
    int* tamanhos = new int[4];
    tamanhos[0] = 0;
    tamanhos[1] = 0;
    tamanhos[2] = 0;
    tamanhos[3] = 0;

    for (int i = 0; i < contVendas; i++)
    {
        int* tamanhosVendas = ListaVendas[i].tamanhoColunas();
        for (int j = 0; j < 4; j++)
        {
            if (tamanhosVendas[j] > tamanhos[j])
            {
                tamanhos[j] = tamanhosVendas[j];
            }
        }
    }

    return tamanhos;
}
void Loja::mostrarVendas()
{
    int* tamanhos = tamanhoColunasVendas();
    int tLinhas = tamanhos[0] + tamanhos[1] + tamanhos[2] + tamanhos[3] + 16;
    string txtTitulo = "=== LISTA DE VENDAS ===";
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
    string cabecalho = "| TALAO";
    for (int i = 0; i < tamanhos[0] - 2; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | DATA ";
    for (int i = 0; i < tamanhos[1] - 4; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | CLIENTE ";
    for (int i = 0; i < tamanhos[2] - 3; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | VALOR TOTAL ";
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

    for (int i = 0; i < contVendas; i++)
    {
        ListaVendas[i].imprimirVendas(tamanhos);
    }
    cout << linha << "\n";
    cout << endl;
}
int Loja::getLastIdVendas()
{
    int maiorId = 0;

    for (int i = 0; i < contVendas; i++)
    {
        int id = ListaVendas[i].getTalao();
        if ( id > maiorId)
        {
            maiorId = id;
        }
    }
    return maiorId;
}
//Relatorios -------------------------------------------------------------------------------

int* Loja::tamanhoColunasImpProdCompras()
{
    int* tamanhos = new int[5];
    tamanhos[0] = 0;
    tamanhos[1] = 0;
    tamanhos[2] = 0;
    tamanhos[3] = 0;
    tamanhos[4] = 0;

    for (int i = 0; i < contProdCompra; i++)
    {
        int* tamanhosProdCompra = ListaProdCompra[i].tamanhoColunas();
        for (int j = 0; j < 5; j++)
        {
            if (tamanhosProdCompra[j] > tamanhos[j])
            {
                tamanhos[j] = tamanhosProdCompra[j];
                // cout << "Tamanhos J: " << tamanhos[j] << endl;
                // sleep(10);
            }
        }
    }

    return tamanhos;
}

void Loja::impRelVendasProd(string nomeProd)
{
    // cout << "Desc Prod: " << ListaProdCompra[0].getDescProd() << endl;
    int* tamanhos = tamanhoColunasImpProdCompras();
    tamanhos[0] = (tamanhos[0] < 5) ? 2 : tamanhos[0];
    tamanhos[1] = (tamanhos[1] < 7) ? 4 : tamanhos[1];
    tamanhos[2] = (tamanhos[2] < 9) ? 6 : tamanhos[2];
    tamanhos[3] = (tamanhos[3] < 3) ? 3 : tamanhos[3];
    tamanhos[4] = (tamanhos[4] < 5) ? 5 : tamanhos[4];
    // cout << "Tamanho: " << tamanhos[0] << " " << tamanhos[1] << " " << tamanhos[2] << " " << tamanhos[3] << " " << tamanhos[4] << endl;
    int tLinhas = tamanhos[0] + tamanhos[1] + tamanhos[2] + tamanhos[3] + tamanhos[4] + 23;
    string txtTitulo = " RELATORIO DE VENDAS POR PRODUTO ";
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
    string cabecalho = "| TALAO";
    for (int i = 0; i < tamanhos[0] - 5; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | ID PROD";
    for (int i = 0; i < tamanhos[1] - 7; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | DESCRICAO ";
    for (int i = 0; i < tamanhos[2] - 9; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | QTD";
    for (int i = 0; i < tamanhos[3] - 3; i++)
    {
        cabecalho += " ";
    }
    cabecalho += " | VALOR";
    for (int i = 0; i < tamanhos[4] - 6; i++)
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

    for (int i = 0; i < contProdCompra; i++)
    {
        if (ListaProdCompra[i].getDescProd() == nomeProd)
        {
            // cout << "Produto: " << nomeProd << endl;
            ListaProdCompra[i].imprimirProdCompra(tamanhos);
        }
    }
    cout << linha << "\n";
    cout << endl;
}

void Loja::impRelVendas()
{
    int* maisVendido = prodMaisVendido();
    int* menosVendido = prodMenosVendido();
    int* maisLucrativo = prodMaisLucrativo();
    int* maisComprador = clienteMaisComprador();

    cout << "\n========================================\n";
    cout << "        RELATORIO GERAL DE VENDAS          \n";
    cout << "========================================\n";

    // Produto mais vendido
    cout << "\n>> Produto Mais Vendido:\n";
    cout << "   - ID: " << maisVendido[0] << "\n";
    cout << "   - Descricao: " << Stock[buscaProduto(maisVendido[0])].getNome() << "\n";
    cout << "   - Quantidade: " << maisVendido[1] << "\n";

    // Produto menos vendido
    cout << "\n>> Produto Menos Vendido:\n";
    cout << "   - ID: " << menosVendido[0] << "\n";
    cout << "   - Descricao: " << Stock[buscaProduto(menosVendido[0])].getNome() << "\n";
    cout << "   - Quantidade: " << menosVendido[1] << "\n";

    // Produto mais lucrativo
    cout << "\n>> Produto Mais Lucrativo:\n";
    cout << "   - ID: " << maisLucrativo[0] << "\n";
    cout << "   - Descricao: " << Stock[buscaProduto(maisLucrativo[0])].getNome() << "\n";
    cout << "   - Lucro: " << auxL.arredondar(maisLucrativo[1]) << " €\n";

    // Cliente que mais comprou
    cout << "\n>> Cliente Que Mais Comprou:\n";
    cout << "   - ID: " << maisComprador[0] << "\n";
    cout << "   - Nome: " << ListaClientes[buscarCliente("ID", to_string(maisComprador[0]))].getNome() << "\n";
    cout << "   - Quantidade de compras: " << maisComprador[1] << "\n";
    cout << "   - Total Gasto: " << auxL.arredondar(maisComprador[2]) << " €\n";

    cout << "========================================\n";

    // Cleanup
    delete[] maisVendido;
    delete[] menosVendido;
    delete[] maisLucrativo;
    delete[] maisComprador;
}

int* Loja::prodMaisVendido()
{
    int* qtd = new int[contProduto];
    int* id = new int[contProduto];
    string* nomes = new string[contProduto];
    int* maisVendido = new int[3]; // [ID, Quantidade, Nome]
    int maiorQtd = 0;
    int pos = 0;

    for (int i = 0; i < contProduto; i++)
    {
        qtd[i] = 0;
        id[i] = Stock[i].getId();
        nomes[i] = Stock[i].getNome();
    }

    for (int i = 0; i < contProdCompra; i++)
    {
        for (int j = 0; j < contProduto; j++)
        {
            if (ListaProdCompra[i].getDescProd() == Stock[j].getNome())
            {
                qtd[j] += ListaProdCompra[i].getQtd();
            }
        }
    }

    for (int i = 0; i < contProduto; i++)
    {
        if (qtd[i] > maiorQtd)
        {
            maiorQtd = qtd[i];
            pos = i;
        }
    }

    maisVendido[0] = id[pos];
    maisVendido[1] = maiorQtd;

    return maisVendido;
}

int* Loja::prodMenosVendido()
{
    int* qtd = new int[contProduto];
    int* id = new int[contProduto];
    string* nomes = new string[contProduto];
    int* menosVendido = new int[3]; // [ID, Quantidade, Nome]
    int menorQtd = 999999;
    int pos = 0;

    for (int i = 0; i < contProduto; i++)
    {
        qtd[i] = 0;
        id[i] = Stock[i].getId();
        nomes[i] = Stock[i].getNome();
    }

    for (int i = 0; i < contProdCompra; i++)
    {
        for (int j = 0; j < contProduto; j++)
        {
            if (ListaProdCompra[i].getDescProd() == Stock[j].getNome())
            {
                qtd[j] += ListaProdCompra[i].getQtd();
            }
        }
    }

    for (int i = 0; i < contProduto; i++)
    {
        if (qtd[i] < menorQtd)
        {
            menorQtd = qtd[i];
            pos = i;
        }
    }

    menosVendido[0] = id[pos];
    menosVendido[1] = menorQtd;

    return menosVendido;
}

int* Loja::prodMaisLucrativo()
{
    int* qtd = new int[contProduto];
    float* preco = new float[contProduto];
    int* id = new int[contProduto];
    string* nomes = new string[contProduto];
    int* maisLucrativo = new int[3]; // [ID, Lucro, Nome]
    float maiorLucro = 0;
    int pos = 0;

    for (int i = 0; i < contProduto; i++)
    {
        qtd[i] = 0;
        id[i] = Stock[i].getId();
        preco[i] = Stock[i].getPreco();
        nomes[i] = Stock[i].getNome();
    }

    for (int i = 0; i < contProdCompra; i++)
    {
        for (int j = 0; j < contProduto; j++)
        {
            if (ListaProdCompra[i].getDescProd() == Stock[j].getNome())
            {
                qtd[j] += ListaProdCompra[i].getQtd();
            }
        }
    }

    for (int i = 0; i < contProduto; i++)
    {
        if (qtd[i] * preco[i] > maiorLucro)
        {
            maiorLucro = qtd[i] * preco[i];
            pos = i;
        }
    }

    maisLucrativo[0] = id[pos];
    maisLucrativo[1] = maiorLucro;

    return maisLucrativo;
}

int* Loja::clienteMaisComprador()
{
    int* qtd = new int[contCliente];
    float* totalGasto = new float[contCliente];
    int* id = new int[contCliente];
    string* nomes = new string[contCliente];
    int* maisComprador = new int[4]; // [ID, Quantidade, Total Gasto, Nome]
    int maiorQtd = 0;
    int pos = 0;

    for (int i = 0; i < contCliente; i++)
    {
        qtd[i] = 0;
        totalGasto[i] = 0;
        id[i] = ListaClientes[i].getId();
        nomes[i] = ListaClientes[i].getNome();
    }

    for (int i = 0; i < contProdCompra; i++)
    {
        for (int j = 0; j < contCliente; j++)
        {
            if (ListaProdCompra[i].getTalao() == ListaClientes[j].getId())
            {
                qtd[j] += ListaProdCompra[i].getQtd();
                totalGasto[j] += ListaProdCompra[i].getQtd() * ListaProdCompra[i].getPreco();
            }
        }
    }

    for (int i = 0; i < contCliente; i++)
    {
        if (qtd[i] > maiorQtd)
        {
            maiorQtd = qtd[i];
            pos = i;
        }
    }

    maisComprador[0] = id[pos];
    maisComprador[1] = maiorQtd;
    maisComprador[2] = totalGasto[pos];

    return maisComprador;
}

//Auxiliares -------------------------------------------------------------------------------
void Loja::preencherDadosIniciais()
{
    //Clientes
    ListaClientes[0] = Cliente(10, "Joao", "123456789", "Rua das Esquinas");
    ListaClientes[1] = Cliente(23, "Maria", "987654321", "Rua das Tolinhas");
    ListaClientes[2] = Cliente(03, "Jose", "123456789", "Rua dos Agrafados");
    ListaClientes[3] = Cliente(04, "Ana", "987654321", "Rua dos Maltrapilhas");
    ListaClientes[4] = Cliente(05, "Pedro", "123456789", "Rua dos Malandros");
    contCliente = 5;

    //Produtos
    Stock[0] = Produto(1, "MASSA", 12, 1.55);
    Stock[1] = Produto(2, "ARROZ", 17, 1.25);
    Stock[2] = Produto(3, "FEIJAO", 22, 1.13);
    Stock[3] = Produto(4, "BATATA", 19, 2.55);
    Stock[4] = Produto(5, "CARNE", 11, 5.58);
    contProduto = 5;

    //Vendas
    ListaVendas[0] = Vendas(1, "03/05/2021", "Joao", 100.5);
    ListaVendas[1] = Vendas(2, "20/01/2022", "Maria", 50.5);
    ListaVendas[2] = Vendas(3, "15/03/2023", "Jose", 62.0);
    ListaVendas[3] = Vendas(4, "04/09/2023", "Eva", 55.0);
    ListaVendas[4] = Vendas(5, "02/05/2024", "Zeca Afonso", 99.45);
    contVendas = 4;

    //ProdCompra
    ListaProdCompra[0] = ProdCompra(1, 1, "MASSA", 10, 10.5);
    ListaProdCompra[1] = ProdCompra(1, 2, "ARROZ", 20, 20.5);
    ListaProdCompra[2] = ProdCompra(1, 3, "FEIJAO", 30, 30.5);
    ListaProdCompra[3] = ProdCompra(2, 5, "CARNE", 50, 50.5);
    ListaProdCompra[4] = ProdCompra(2, 4, "BATATA", 40, 40.5);
    ListaProdCompra[5] = ProdCompra(2, 3, "FEIJAO", 15, 30.5);
    ListaProdCompra[6] = ProdCompra(2, 2, "ARROZ", 10, 20.5);
    ListaProdCompra[7] = ProdCompra(3, 1, "MASSA", 5, 10.5);
    ListaProdCompra[8] = ProdCompra(3, 4, "BATATA", 25, 40.5);
    ListaProdCompra[9] = ProdCompra(3, 5, "CARNE", 30, 50.5);
    contProdCompra = 10;
}