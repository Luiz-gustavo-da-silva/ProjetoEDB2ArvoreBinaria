#ifndef NO_H
#define NO_H

using namespace std;


class No {
public:
    int chave;
    int tamanho; // Tamanho da subárvore enraizada neste nó
    int qNoSubarvoresEsquerda;
    int qNoSubarvoresDireita;
    No * filhoEsquerda;
    No * filhoDireita;

    No(int valor);

};


#endif