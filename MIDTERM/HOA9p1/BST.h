#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

template <typename T>
class BinarySearchTree{
    private:
        T key;
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;

        std::vector<GeneralTree<T>*> children;

    public:
        // Constructor
        BinarySearchTree(T value);
        // Insertion
        void insert(T value);

        // add node
        void addChild(T value);
        GeneralTree<T>* addChildAndReturn(T value);

        // get child index
        GeneralTree<T>* getChild(size_t index);

        // Traversal
        void preOrder();
        void inOrder();
        void postOrder();
};


template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
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

    if(left != nullptr){
        left->preOrder();
    }
    if(right != nullptr){
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        left->inOrder();
    }
    std::cout << key << " ";
    if(right != nullptr){
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
     if(left != nullptr){
        left->postOrder();
    }
    if(right != nullptr){
        right->postOrder();
    }
    std::cout << key << " ";
}



#endif