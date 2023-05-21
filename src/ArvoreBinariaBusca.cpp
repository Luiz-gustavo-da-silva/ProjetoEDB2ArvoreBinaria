#include "../include/ArvoreBuscaBinaria.h"

#include <iostream>

using namespace std;

No *ArvoreBuscaBinaria::insertNode(No *node, int key)
{
    if (node == nullptr)
    {
        return new No(key);
    }

    if (key < node->chave)
    {
        node->filhoEsquerda = insertNode(node->filhoEsquerda, key);
    }
    else
    {
        node->filhoDireita = insertNode(node->filhoDireita, key);
    }

    node->tamanho++; // Atualiza o tamanho da subárvore enraizada neste nó

    return node;
}

No *ArvoreBuscaBinaria::removeNode(No *node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (key < node->chave)
    {
        node->filhoEsquerda = removeNode(node->filhoEsquerda, key);
    }
    else if (key > node->chave)
    {
        node->filhoDireita = removeNode(node->filhoDireita, key);
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

int ArvoreBuscaBinaria::rank(No *node, int key)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (key < node->chave)
    {
        return rank(node->filhoEsquerda, key);
    }
    else if (key > node->chave)
    {
        return 1 + getSize(node->filhoEsquerda) + rank(node->filhoDireita, key);
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

ArvoreBuscaBinaria::ArvoreBuscaBinaria()
{
    root = nullptr;
}

void ArvoreBuscaBinaria::insert(int key)
{
    root = insertNode(root, key);
}

void ArvoreBuscaBinaria::remove(int key)
{
    root = removeNode(root, key);
}

bool ArvoreBuscaBinaria::search(int key)
{
    No *current = root;
    while (current != nullptr)
    {
        if (key == current->chave)
        {
            return true;
        }
        else if (key < current->chave)
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

int ArvoreBuscaBinaria::rank(int key)
{
    return rank(root, key);
}