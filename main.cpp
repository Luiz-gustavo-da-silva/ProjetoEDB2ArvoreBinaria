#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "./include/ArvoreBinariaBusca.h"

using namespace std;

int main(int argc, char *argv[])
{

    ArvoreBinariaBusca abb;

    ifstream arquivoL;
    ifstream arquivoLEntradas;
    ofstream arquivoS;

    string linha;
    int posicao;
    int numeroInteiro;

    if(argc < 4){
        cout << "ERRO: Informe os arquivos de entrada e saída corretamente";
        return 0;
    }

    // Adição do arquivo de saída ao objeto criado
    abb.setCaminhoSaida(argv[3]);
    
    // Leitura do arquivo de entrada com os valores da árvore
    arquivoL.open(argv[1]);

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

    arquivoLEntradas.open(argv[2]);

    if (arquivoLEntradas.is_open())
    {

        // Abertura do arquivo de saída, caso não exita ele é criado.

        arquivoS.open(argv[3], ios::app);

        if (arquivoS.is_open())
        {

            while (getline(arquivoLEntradas, linha))
            {
                std::istringstream iss(linha);
                std::string command, numberStr;
                int number = -1;

                if (iss >> command >> numberStr)
                {
                    std::istringstream numberIss(numberStr);
                    if (!(numberIss >> number))
                    {
                        number = -1;
                    }
                }
              

                if (command == "CHEIA")
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
                else if (command == "COMPLETA")
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
                else if (command == "ENESIMO")
                {

                    // Lógica para a opção ENESIMO com o valor de n
                    

                    if (abb.enesimoElemento(number) != -1)
                    {
                        arquivoS << abb.enesimoElemento(number) << endl;
                    }
                    else
                    {
                        arquivoS << "ERRO" << endl;
                    }
                }
                else if (command == "INSIRA")
                {

                    // Lógica para a opção INSIRA com o valor especificado
                    //cout << op2 << endl;
                    if (abb.inserir(number) == true)
                    {
                        arquivoS << number << " ";
                        arquivoS << "adicionado" << endl;
                    }
                    else
                    {
                        arquivoS << number << " ";
                        arquivoS << "já está na árvore, não pode ser inserido" << endl;
                    }

                }
                else if (command == "PREORDEM")
                {
                    // Lógica para a opção PREORDEM

                    arquivoS << abb.pre_ordem() << endl;
                }
                else if (command == "IMPRIMA")
                {

                    // Lógica para a opção IMPRIMA com o tipo especificado
                    
                    abb.imprimeArvore(number);
                }
                else if (command == "REMOVA")
                {

                    // Lógica para a opção REMOVA com o valor especificado

                    if (abb.removeInicial(number))
                    {
                        arquivoS << number << " removido" << endl;
                    }
                    else
                    {
                        arquivoS << number <<" não está na árvore, não pode ser removido" << endl;
                    } 

                }
                else if (command == "POSICAO")
                {

                    // Lógica para a opção POSICAO com o valor especificado
                    

                    arquivoS << abb.posicao(number) << endl;
                }
                else if (command == "MEDIANA")
                {
                    // Lógica para a opção MEDIANA

                    arquivoS << abb.mediana() << endl;
                }
                else if (command == "MEDIA")
                {

                    // Lógica para a opção MEDIA com o valor especificado

                    arquivoS << abb.media(number) << endl;
                }
                else if (command == "BUSCAR")
                {

                    // Lógica para a opção BUSCAR com o valor especificado

                    if (abb.buscar(number))
                    {
                        arquivoS << "Chave encontrada" << endl;
                    }
                    else
                    {
                        arquivoS << "Chave não encontrada" << endl;
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
