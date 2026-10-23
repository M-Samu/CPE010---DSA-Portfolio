#include <iostream>
#include "BST2.h"

int main() {
    BinarySearchTree<char>* root = new BinarySearchTree<char>('A');

    root->addChild('B');
    root->addChild('C');
    BinarySearchTree<char>* d = root->addChildAndReturn('D');
    BinarySearchTree<char>* e = root->addChildAndReturn('E');
    BinarySearchTree<char>* f = root->addChildAndReturn('F');
    BinarySearchTree<char>* g = root->addChildAndReturn('G');

    d->addChild('H');

    e->addChild('I');
    BinarySearchTree<char>* j = e->addChildAndReturn('J');

    j->addChild('P');
    j->addChild('Q');

    f->addChild('K');
    f->addChild('L');
    f->addChild('M');

    g->addChild('N');

    std::cout << "Post-Order Traversal: ";
    root->postOrder();
    std::cout << "\n";

    std::cout << "Pre-Order Traversal: ";
    root->preOrder();
    std::cout << "\n";


    std::cout << "In-Order Traversal: ";
    root->inOrder();
    std::cout << "\n";

    std::cout << "Finding Data P: ";
    root->findData('P');
    std::cout << "\n";

    delete root;
    return 0;
}