#ifndef ARVOREBINARIABUSCA_H
#define ARVOREBINARIABUSCA_H

using namespace std;

#include <string>
#include "./No.h"

class ArvoreBinariaBusca
{

private:
    No *raiz;

    No *inserirNo(No *no, int chave);

    No *removeNo(No *no, int chave);

    No *getMinNode(No *no);

    int getAlturaNo(No *no, int chave);

    int getSize(No *no);

public:
    ArvoreBinariaBusca();

    ~ArvoreBinariaBusca();

    // void deleteTree(No *Noatual);

    // No * obterRaiz();

    void inserir(int chave);

    void remove(int chave);

    bool buscar(int chave);

    int alturaNo(int chave);

    int getEnesimoElemento(No *no, int n);

    int enesimoElemento(int n);

// Ainda não fiz
    int posicao(int x);

    int mediana ();

    double media (int x);

    bool ehCheia ();

    bool ehCompleta ();

    string pre_ordem ();

    void imprimeArvore (int s);
};

#endif