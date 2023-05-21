#include <iostream>

class TreeNode {
public:
    int key;
    int size; // Tamanho da subárvore enraizada neste nó
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        key = value;
        size = 1;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }

        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }

        node->size++; // Atualiza o tamanho da subárvore enraizada neste nó

        return node;
    }

    TreeNode* removeNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = removeNode(node->left, key);
        } else if (key > node->key) {
            node->right = removeNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* successor = getMinNode(node->right);
            node->key = successor->key;
            node->right = removeNode(node->right, successor->key);
        }

        node->size--; // Atualiza o tamanho da subárvore enraizada neste nó

        return node;
    }

    TreeNode* getMinNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    int rank(TreeNode* node, int key) {
        if (node == nullptr) {
            return 0;
        }

        if (key < node->key) {
            return rank(node->left, key);
        } else if (key > node->key) {
            return 1 + getSize(node->left) + rank(node->right, key);
        } else {
            return getSize(node->left);
        }
    }

    int getSize(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->size;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = removeNode(root, key);
    }

    bool search(int key) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (key == current->key) {
                return true;
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    int rank(int key) {
        return rank(root, key);
    }
};

int main() {
    BinarySearchTree bst;

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
