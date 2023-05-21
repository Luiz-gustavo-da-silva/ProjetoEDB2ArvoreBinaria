#include <iostream>

#include "./include/ArvoreBinariaBusca.h"

using namespace std;

int main() {
    ArvoreBuscaBinaria bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    std::cout << "Searching for 6: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 9: " << (bst.search(9) ? "Found" : "Not Found") << std::endl;

    bst.remove(6);
    std::cout << "Searching for 6 after removal: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;

    std::cout << "Rank of 7: " << bst.rank(7) << std::endl;

    return 0;
}
