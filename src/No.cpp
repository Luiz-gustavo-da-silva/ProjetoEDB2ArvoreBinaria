#include "../include/No.h"

#include <iostream>

using namespace std;

No::No(int valor)
{
    chave = valor;
    tamanho = 1;
    filhoEsquerda = nullptr;
    filhoDireita = nullptr;
}