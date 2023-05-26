#ifndef ARVOREBINARIABUSCA_H
#define ARVOREBINARIABUSCA_H

using namespace std;

#include <string>
#include <stack>
#include <vector>

#include "./No.h"

class ArvoreBinariaBusca
{

private:

   
    No *raiz;

    No *inserirNo(No *no, int chave);

    int getAlturaNo(No* node, int key, int height);

    int getMediana(No * no, int tamanhoArvore);

    int getTamanho(No *no);

    void getEnesimoElemento(No *no, int n, int & cont, int & resultado);

    void getPosicao(No *no, int &cont, int & x, int & resultadoFinal);

    void getPre_ordem(No *no, string & valor);

    void getEhCheia(No*no, int & tamanhoArvore, bool & ehCheiaResultado);

    void getEhCompleta(No *no, int &tamanhoArvore, bool &ehCompletaResultado);

    void imprimeFormartoUm(No * no, string &arvore);

    void imprimeFormartoDois(No *no, string &arvore, int tracos, vector<string> & linhasOp2);

    void getMedia(No* no, No * noInicial, double & soma, double & cont, int & resultadoFinal);

    No * getBuscar(int chave);

    int getTamanhoArvore(No * no);

    void inserirNaoRecursivo(int chave);

    void removerBusca(int chave, No *& noatual);

    void deletarNo(No *& noatual);

    void obterSucessor(int & chave, No* temp );

    int tamanhoArvore();
 
    int alturaNo(int chave);

    void remove(int chave);

public:

    // Cosntrutores

    ArvoreBinariaBusca();

    ~ArvoreBinariaBusca();

    // Método para apagar todos os ponteiros da árvore
    
    void deletarArvore(No * noatual);

    // Métodos principais

    bool inserir(int chave);

    bool removeInicial(int chave);

    bool buscar(int chave);

    int enesimoElemento(int n);

    int posicao(int x);

    int mediana ();

    double media (int x);

    bool ehCheia ();

    bool ehCompleta ();

    string pre_ordem ();

    void imprimeArvore (int s);

    string caminhoSaida;

    void setCaminhoSaida(string caminhoSaida);

};

#endif