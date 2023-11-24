#pragma once
#include "bst.h"

using namespace std;

class AVLTree: public BinarySearchTree {
public:
    AVLTree() { };
    ~AVLTree() { };

    int insert(int key);
    int remove(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    Node* insertNode(Node* cur, const int &key);
    Node* deleteNode(Node* cur, const int &target);
    Node* search(Node* cur, const int &target);
    void updateHeight(Node* cur) {
        if(cur->left==NULL && cur->right==NULL) {
            // in case after rotation
            cur->height = 0;
        }
        else if(cur->left!=NULL && cur->right!=NULL) {
            cur->height = cur->left->height < cur->right->height ? 
                            1+cur->right->height : 1+cur->left->height;
        }
        else {
            cur->height = cur->left==NULL ? 1+cur->right->height : 1+cur->left->height;
        }
    }
    int getBF(Node* cur) {
        if(cur==NULL) {
            return -1;
        }
        else if(cur->left!=NULL && cur->right!=NULL) {
            return cur->left->height - cur->right->height;
        }
        else if(cur->left==NULL && cur->right==NULL){
            return 0;
        }
        else {
            return cur->left==NULL ? 1+cur->right->height : 1+cur->left->height;
        }
    }
    int getHeight(Node* node) {
        return node==NULL ? -1 : node->height;
    }
    int abs(int x) {return x>0 ? x : -x;}
    Node* restoreBalance(Node* cur);
    Node* rotateLL(Node* root);
    Node* rotateRR(Node* root);
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};