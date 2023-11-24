#pragma once
#include "tree.h"

using namespace std;

class BinarySearchTree: public BinaryTree {
public:
    BinarySearchTree() { };
    ~BinarySearchTree() { };

    int insert(int key);
    int remove(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    Node* find(Node* cur, const int &target);
    Node* deleteNode(Node* cur, const int &target);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};