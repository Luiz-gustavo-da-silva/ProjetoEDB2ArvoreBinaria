#include <iostream>
#include <fstream>
#include <string>

#include "./include/ArvoreBinariaBusca.h"

using namespace std;

int main()
{

    ArvoreBinariaBusca abb;

    ifstream arquivoL;
    ifstream arquivoLEntradas;
    ofstream arquivoS;

    string linha;
    int posicao;
    string op1;
    string op2;
    int numeroInteiro;

    // Leitura do arquivo de entrada com os valores da árvore

    arquivoL.open("/home/luiz/Área de Trabalho/ProjetoEDB2ArvoreBinaria/arquivos/entrada/arquivo1.txt");

    if (arquivoL.is_open())
    {
        int numero;
        while (arquivoL >> numero)
        {
            abb.inserir(numero);
        }

        arquivoL.close();
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }

    // Leitura dos comandos

    arquivoLEntradas.open("/home/luiz/Área de Trabalho/ProjetoEDB2ArvoreBinaria/arquivos/entrada/arquivo2.txt");

    if (arquivoLEntradas.is_open())
    {
        arquivoS.open("/home/luiz/Área de Trabalho/ProjetoEDB2ArvoreBinaria/arquivos/saída/saida.txt", ios::app);

        if (arquivoS.is_open())
        {

            while (getline(arquivoLEntradas, linha))
            {
                if (!linha.empty() && linha[linha.size() - 1] == '\r')
                {
                    linha.erase(linha.size() - 1);
                }
                posicao = linha.find(" ");

                if (posicao != -1)
                {
                    op1 = linha.substr(0, posicao);
                    op2 = linha.substr(posicao + 1, linha.size() - 1);
                }
                else
                {
                    op2 = -2;
                }

                if (!op2.empty() && op2[op2.size() - 1] == '\r')
                {
                    op2.erase(op2.size() - 1);
                }

                if (linha == "CHEIA")
                {
                    // Lógica para a opção CHEIA

                    if (abb.ehCheia())
                    {
                        arquivoS << "A árvore é cheia" << endl;
                    }
                    else
                    {
                        arquivoS << "A árvore não é cheia" << endl;
                    }
                }
                else if (linha == "COMPLETA")
                {

                    // Lógica para a opção COMPLETA

                    if (abb.ehCompleta())
                    {
                        arquivoS << "A árvore é completa" << endl;
                    }
                    else
                    {
                        arquivoS << "A árvore não é completa" << endl;
                    }
                }
                else if (op1 == "ENESIMO")
                {

                    // Lógica para a opção ENESIMO com o valor de n
                    numeroInteiro = std::stoi(op2);

                    if (abb.enesimoElemento(numeroInteiro) != -1)
                    {
                        arquivoS << abb.enesimoElemento(numeroInteiro) << endl;
                    }
                    else
                    {
                        arquivoS << "ERRO" << endl;
                    }
                }
                else if (op1 == "INSIRA")
                {

                    // Lógica para a opção INSIRA com o valor especificado

                    numeroInteiro = std::stoi(op2);

                    if (abb.inserir(numeroInteiro) == true)
                    {
                        arquivoS << op2 << " adicionado" << endl;
                    }
                    else
                    {
                        arquivoS << op2 << " já está na árvore, não pode ser inserido" << endl;
                    }
                }
                else if (linha == "PREORDEM")
                {
                    // Lógica para a opção PREORDEM

                    arquivoS << abb.pre_ordem() << endl;
                }
                else if (op1 == "IMPRIMA")
                {

                    // Lógica para a opção IMPRIMA com o tipo especificado
                    numeroInteiro = std::stoi(op2);

                    abb.imprimeArvore(numeroInteiro);
                }
                else if (op1 == "REMOVA")
                {

                    // Lógica para a opção REMOVA com o valor especificado

                    numeroInteiro = std::stoi(op2);

                    if (abb.removeInicial(numeroInteiro))
                    {
                        arquivoS << op2 << " removido" << endl;
                    }
                    else
                    {
                        arquivoS << op2 << " não está na árvore, não pode ser removido" << endl;
                    }
                }
                else if (op1 == "POSICAO")
                {

                    // Lógica para a opção POSICAO com o valor especificado
                    numeroInteiro = std::stoi(op2);

                    arquivoS << abb.posicao(numeroInteiro) << endl;
                }
                else if (linha == "MEDIANA")
                {
                    // Lógica para a opção MEDIANA

                    arquivoS << abb.mediana() << endl;
                }
                else if (op1 == "MEDIA")
                {

                    // Lógica para a opção MEDIA com o valor especificado

                    numeroInteiro = std::stoi(op2);

                    arquivoS << abb.media(numeroInteiro) << endl;
                }
                else if (op1 == "BUSCAR")
                {

                    // Lógica para a opção BUSCAR com o valor especificado

                    numeroInteiro = std::stoi(op2);

                    if (abb.buscar(numeroInteiro))
                    {
                        arquivoS << " Chave encontrada" << endl;
                    }
                    else
                    {
                        arquivoS << " Chave não encontrada" << endl;
                    }
                }
                else
                {
                    cout << "Opção inválida." << endl;
                }
            }
        }
        else
        {
            std::cout << "Não foi possível abrir o arquivo." << std::endl;
        }

        arquivoS.close();
        arquivoL.close();
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }

    return 0;
}
