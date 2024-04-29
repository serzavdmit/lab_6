#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void printTree() {
        if (!root) {
            std::cout << "Дерево порожнє" << std::endl;
            return;
        }
        printTreeRecursive(root, 0);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    int findMax() {
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    void printTreeRecursive(Node* current, int level) {
        if (current == nullptr) {
            return;
        }

        printTreeRecursive(current->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << current->data << std::endl;
        printTreeRecursive(current->left, level + 1);
    }

    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }
        if (current->data == value) {
            return true;
        }
        if (value < current->data) {
            return searchRecursive(current->left, value);
        }
        return searchRecursive(current->right, value);
    }
};

int main() 
{
    setlocale(LC_ALL,"Ukr");
    BST tree;
    int n, value, searchValue;

    std::cout << "Введіть кількість елементів у дереві: ";
    std::cin >> n;

    std::cout << "Введіть " << n << " цілих чисел: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        tree.insert(value);
    }

    std::cout << "\nДерево:" << std::endl;
    tree.printTree();

    std::cout << "\nВведіть число для пошуку: ";
    std::cin >> searchValue;
    if (tree.search(searchValue)) {
        std::cout << searchValue << " знайдено у дереві." << std::endl;
    }
    else {
        std::cout << searchValue << " не знайдено у дереві." << std::endl;
    }

    std::cout << "Максимальний елемент у дереві: " << tree.findMax() << std::endl;

    return 0;
}
