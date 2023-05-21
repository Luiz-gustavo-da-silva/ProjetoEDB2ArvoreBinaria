#ifndef ARVOREBUSCABINARIA_H
#define ARVOREBUSCABINARIA_H

using namespace std;

#include "./No.h"
#include <string>

class ArvoreBuscaBinaria {
    
private:
    No* raiz;

    No* insertNode(No* node, int chave);

    No* removeNode(No* node, int chave);

    No* getMinNode(No* node);

    int rank(No* node, int chave);

    int getSize(No* node);

public:

    ArvoreBuscaBinaria();

    ~ArvoreBuscaBinaria();
    
    void deleteTree(No *Noatual);

    No * obterRaiz();
    
    bool isEmpty();

    bool itIsNotEmpty();

    void insert(int chave);

    void remove(int chave);

    bool search(int chave);

    int rank(int chave);

    string pre_ordem(No *Noatual);

    void imprimeArvore (int s);
};

#endif