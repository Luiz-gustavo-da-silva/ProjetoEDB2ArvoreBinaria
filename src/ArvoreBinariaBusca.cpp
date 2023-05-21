#include "../include/ArvoreBuscaBinaria.h"

#include <iostream>
#include <cstddef>

using namespace std;

No *ArvoreBuscaBinaria::insertNode(No *node, int chave)
{
    if (node == nullptr)
    {
        return new No(chave);
    }

    if (chave < node->chave)
    {
        node->filhoEsquerda = insertNode(node->filhoEsquerda, chave);
    }
    else
    {
        node->filhoDireita = insertNode(node->filhoDireita, chave);
    }

    node->tamanho++; // Atualiza o tamanho da subárvore enraizada neste nó

    return node;
}

No *ArvoreBuscaBinaria::removeNode(No *node, int chave)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (chave < node->chave)
    {
        node->filhoEsquerda = removeNode(node->filhoEsquerda, chave);
    }
    else if (chave > node->chave)
    {
        node->filhoDireita = removeNode(node->filhoDireita, chave);
    }
    else
    {
        if (node->filhoEsquerda == nullptr)
        {
            No *temp = node->filhoDireita;
            delete node;
            return temp;
        }
        else if (node->filhoDireita == nullptr)
        {
            No *temp = node->filhoEsquerda;
            delete node;
            return temp;
        }

        No *successor = getMinNode(node->filhoDireita);
        node->chave = successor->chave;
        node->filhoDireita = removeNode(node->filhoDireita, successor->chave);
    }

    node->tamanho--; // Atualiza o tamanho da subárvore enraizada neste nó

    return node;
}

No *ArvoreBuscaBinaria::getMinNode(No *node)
{
    No *current = node;
    while (current->filhoEsquerda != nullptr)
    {
        current = current->filhoEsquerda;
    }
    return current;
}

int ArvoreBuscaBinaria::rank(No *node, int chave)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (chave < node->chave)
    {
        return rank(node->filhoEsquerda, chave);
    }
    else if (chave > node->chave)
    {
        return 1 + getSize(node->filhoEsquerda) + rank(node->filhoDireita, chave);
    }
    else
    {
        return getSize(node->filhoEsquerda);
    }
}

int ArvoreBuscaBinaria::getSize(No *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->tamanho;
}

ArvoreBuscaBinaria::ArvoreBuscaBinaria() // Construtor
{
    raiz = nullptr;
}
ArvoreBuscaBinaria::~ArvoreBuscaBinaria(){ // Destrutor

}

No * ArvoreBuscaBinaria::obterRaiz(){
    return raiz;
}



bool ArvoreBuscaBinaria::isEmpty(){
    return raiz == nullptr;
}


bool ArvoreBuscaBinaria::itIsNotEmpty(){
    return raiz != nullptr;
}



void ArvoreBuscaBinaria::insert(int chave)
{
    raiz = insertNode(raiz, chave);
}

void ArvoreBuscaBinaria::remove(int chave)
{
    raiz = removeNode(raiz, chave);
}

bool ArvoreBuscaBinaria::search(int chave)
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

int ArvoreBuscaBinaria::rank(int chave)
{
    return rank(raiz, chave);
}