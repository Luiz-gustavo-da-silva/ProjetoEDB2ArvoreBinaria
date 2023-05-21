#ifndef ARVOREBUSCABINARIA_H
#define ARVOREBUSCABINARIA_H

using namespace std;

#include "./No.h"

class ArvoreBuscaBinaria {
    
private:
    No* root;

    No* insertNode(No* node, int key);

    No* removeNode(No* node, int key);

    No* getMinNode(No* node);

    int rank(No* node, int key);

    int getSize(No* node);

public:

    ArvoreBuscaBinaria();

    void insert(int key);

    void remove(int key);

    bool search(int key);

    int rank(int key);
};

#endif