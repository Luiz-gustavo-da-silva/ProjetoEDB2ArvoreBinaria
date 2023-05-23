#include <iostream>

#include "./include/ArvoreBinariaBusca.h"

using namespace std;

int main() {

    ArvoreBinariaBusca bst;

    bst.inserir(8);
    bst.inserir(3);
    bst.inserir(10);
    bst.inserir(1);
    bst.inserir(6);
    bst.inserir(14);
    bst.inserir(4);
    bst.inserir(7);
    bst.inserir(13);

    cout << (bst.buscar(6) ? "Sim" : "Não") << std::endl;
    cout << (bst.buscar(9) ? "Sim" : "Não") << endl;

    bst.remove(6);
    cout << (bst.buscar(6) ? "Sim" : "Não") << endl;

    cout << "Rank of 7: " << bst.alturaNo(7) << endl;

    return 0;
}
