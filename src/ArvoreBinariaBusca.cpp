#include "../include/ArvoreBinariaBusca.h"

#include <iostream>
#include <cstddef>

using namespace std;

No *ArvoreBinariaBusca::inserirNo(No *no, int chave)
{
    if (no == nullptr)
    {
        return new No(chave);
    }

    if (chave < no->chave)
    {
        no->filhoEsquerda = inserirNo(no->filhoEsquerda, chave);
    }
    else
    {
        no->filhoDireita = inserirNo(no->filhoDireita, chave);
    }

    no->tamanho++; // Atualiza o tamanho da subárvore enraizada neste nó

    return no;
}

No *ArvoreBinariaBusca::removeNo(No *no, int chave)
{
    if (no == nullptr)
    {
        return nullptr;
    }

    if (chave < no->chave)
    {
        no->filhoEsquerda = removeNo(no->filhoEsquerda, chave);
    }
    else if (chave > no->chave)
    {
        no->filhoDireita = removeNo(no->filhoDireita, chave);
    }
    else
    {
        if (no->filhoEsquerda == nullptr)
        {
            No *temp = no->filhoDireita;
            delete no;
            return temp;
        }
        else if (no->filhoDireita == nullptr)
        {
            No *temp = no->filhoEsquerda;
            delete no;
            return temp;
        }

        No *successor = getMinNode(no->filhoDireita);
        no->chave = successor->chave;
        no->filhoDireita = removeNo(no->filhoDireita, successor->chave);
    }

    no->tamanho--; // Atualiza o tamanho da subárvore enraizada neste nó

    return no;
}

No *ArvoreBinariaBusca::getMinNode(No *node)
{
    No *current = node;
    while (current->filhoEsquerda != nullptr)
    {
        current = current->filhoEsquerda;
    }
    return current;
}

int ArvoreBinariaBusca::getAlturaNo(No *node, int chave)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (chave < node->chave)
    {
        return getAlturaNo(node->filhoEsquerda, chave);
    }
    else if (chave > node->chave)
    {
        return 1 + getSize(node->filhoEsquerda) + getAlturaNo(node->filhoDireita, chave);
    }
    else
    {
        return getSize(node->filhoEsquerda);
    }
}

int ArvoreBinariaBusca::getSize(No *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->tamanho;
}

ArvoreBinariaBusca::ArvoreBinariaBusca() // Construtor
{
    raiz = nullptr;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca()
{ // Destrutor
}

/*No * ArvoreBinariaBusca::obterRaiz(){
    return raiz;
}


bool ArvoreBinariaBusca::isEmpty(){
    return raiz == nullptr;
}


bool ArvoreBinariaBusca::itIsNotEmpty(){
    return raiz != nullptr;
}*/

void ArvoreBinariaBusca::inserir(int chave)
{
    raiz = inserirNo(raiz, chave);
}

void ArvoreBinariaBusca::remove(int chave)
{
    raiz = removeNo(raiz, chave);
}

bool ArvoreBinariaBusca::buscar(int chave)
{
    No *current = raiz;
    while (current != nullptr)
    {
        if (chave == current->chave)
        {
            return true;
        }
        else if (chave < current->chave)
        {
            current = current->filhoEsquerda;
        }
        else
        {
            current = current->filhoDireita;
        }
    }
    return false;
}

int ArvoreBinariaBusca::alturaNo(int chave)
{
    return getAlturaNo(raiz, chave);
}

int ArvoreBinariaBusca::enesimoElemento(int n)
{
    if (n < 1 || n > getSize(raiz))
    {
        //throw std::out_of_range("Invalid index");
        cout << "Invalid index" << endl;
        return -1;
    }
    return getEnesimoElemento(raiz, n);
}

int ArvoreBinariaBusca::getEnesimoElemento(No *no, int n)
{

    int leftSize = getSize(no->filhoEsquerda);

    if (n <= leftSize)
    {
        return getEnesimoElemento(no->filhoEsquerda, n);
    }
    else if (n == leftSize + 1)
    {
        return no->chave;
    }
    else
    {
        return getEnesimoElemento(no->filhoDireita, n - leftSize - 1);
    }
}


int ArvoreBinariaBusca::posicao(int x){

}