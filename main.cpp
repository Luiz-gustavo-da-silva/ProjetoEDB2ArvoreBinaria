#include <iostream>

#include "./include/ArvoreBinariaBusca.h"

using namespace std;

int main() {

    ArvoreBinariaBusca bst;

    bst.inserir(8);
    bst.inserir(3);
    bst.inserir(1);
    bst.inserir(6);
    bst.inserir(4);
    bst.inserir(7);
    bst.inserir(10);


/*       8
        / \
       3   10
      / \    
     1   6    
        / \   
       4   7 
*/  
    //cout << bst.pre_ordem()<< endl;
    //bst.imprimeArvore(2);
    //cout << bst.enesimoElemento(6);
    //cout << bst.posicao(6) << endl;

    //cout << bst.media(13)<< endl;
    //cout << bst.tamanhoArvore();
    //cout << bst.ehCompleta() << endl;
    //cout << bst.mediana();

    bst.remove(10);
    cout << bst.buscar(10) << endl;
    cout << bst.mediana() << endl;
    cout << bst.enesimoElemento(3);

    return 0;
}
