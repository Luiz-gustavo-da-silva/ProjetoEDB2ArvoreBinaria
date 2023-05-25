#ifndef NO_H
#define NO_H

using namespace std;


class No {
public:
    int chave;
    int tamanho;
    No * filhoEsquerda;  
    No * filhoDireita;

    No(int valor);

};


#endif