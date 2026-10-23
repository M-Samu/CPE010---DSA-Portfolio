#ifndef BST2_H
#define BST2_H

#include <iostream>
#include <vector>

template <typename T>
class BinarySearchTree{
    private:
        T key;
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;

        std::vector<BinarySearchTree<T>*> children;

        bool searchPreOrder(T targetKey);

    public:
        // Constructor
        BinarySearchTree(T value);
        // Insertion
        void insert(T value);

        // add node
        void addChild(T value);
        BinarySearchTree<T>* addChildAndReturn(T value);

        // get child index
        BinarySearchTree<T>* getChild(size_t index);

        // Traversal
        void preOrder();
        void inOrder();
        void postOrder();

        // finding data
        void findData( T key);
    
};


template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    right = nullptr;
    left = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value){
    // go to the left if the value < key
    if(value < key){
        if(left == nullptr){
            left = new BinarySearchTree(value);
        }
        else{
            left->insert(value);
    }
}

    // go to the rigt if the value > key
    else if(value > key){
        if(right == nullptr){
            right = new BinarySearchTree(value);
        }else{
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << " ";

    for (auto child : children){
        child->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (children.empty()) {
        std::cout << key << " ";
        return;
    }

    children[0]->inOrder();

    std::cout << key << " ";

    for (size_t i = 1; i < children.size(); ++i) {
        children[i]->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
    for (auto child : children){
        child->preOrder();
    }
    std::cout << key << " ";
}

template <typename T>
void BinarySearchTree<T>::addChild(T value){
    children.push_back(new BinarySearchTree<T>(value));
}

template <typename T> 
BinarySearchTree<T>* BinarySearchTree<T>::addChildAndReturn(T value){
    BinarySearchTree<T>* childNode = new BinarySearchTree<T>(value);
    children.push_back(childNode);
    return childNode;
}

template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::getChild(size_t index){
    if (index <children.size()){
        return children[index];
    }
    return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::searchPreOrder(T targetKey) {
    if (key == targetKey) return true;
    for (auto child : children) {
        if (child->searchPreOrder(targetKey)) return true;
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::findData(T key) {
    if (searchPreOrder(key)) {
        std::cout << key << " was found!" << std::endl;
    }
}
#endif