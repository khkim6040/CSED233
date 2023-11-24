#include "tree.h"
#include "bst.h"
#include "avl.h"
#include <iostream>
#include <string>

using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

Node* AVLTree::search(Node* cur, const int &target) {
    if(cur==NULL) {
        return NULL;
    }

    if(cur->key == target) {
        return cur;
    }
    else if(target < cur->key) {
        return search(cur->left, target);
    }
    else {
        return search(cur->right, target);
    }
}

Node* AVLTree::insertNode(Node* cur, const int &key) {
    if(cur == NULL) {
        Node* temp = new Node(key);
        return temp;
    }

    if(key < cur->key) {
        cur->left = insertNode(cur->left, key);
    }
    else {
        cur->right = insertNode(cur->right, key);
    }
    // height update
    updateHeight(cur);
    // check if violation occured
    if(abs(getBF(cur)) > 1) {
        // violation occured
        return restoreBalance(cur);
    }
    else {
        return cur;
    }
}

Node* AVLTree::restoreBalance(Node* cur) {
    // std::cout << cur->key << '\n';
    if(getBF(cur) > 0) {
        // LL case
        int h_ll = getHeight(cur->left->left);
        int h_lr = getHeight(cur->left->right);
        if(h_ll >= h_lr) {
            return rotateLL(cur);
        }
        // LR case
        else {
            cur->left = rotateRR(cur->left);
            return rotateLL(cur);
        }
    }
    else { 
        // RR case
        if(getBF(cur->right) <= 0) {
            return rotateRR(cur);
        }
        // RL case
        else {
            cur->right = rotateLL(cur->right);
            return rotateRR(cur);
        }             
    }
}

Node* AVLTree::rotateLL(Node* root) {
    Node* temp = root->left;
    Node* right_sub = temp->right;
    temp->right = root;
    root->left = right_sub;
    // update height
    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node* AVLTree::rotateRR(Node* root) {
    Node* temp = root->right;
    Node* left_sub = temp->left;
    temp->left = root;
    root->right = left_sub;
    // update height
    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node* AVLTree::deleteNode(Node* cur, const int &target) {
    if(target == cur->key) {
        // degree 0 or 1
        if(cur->left == NULL || cur->right == NULL) {
            Node* temp = cur->left == NULL ? cur->right : cur->left;
            delete cur;
            cur = NULL;
            return temp;
        }
        // degree 2
        else {
            // 오른쪽 subtree에서 가장 작은 값 찾기
            Node* min_node = cur->right;
            Node* parent_of_min_node = NULL;
            while(min_node->left) {
                parent_of_min_node = min_node;
                min_node = min_node->left;
            }
            // 삭제 대상 노드에 해당 값 넣기
            cur->key = min_node->key;
            parent_of_min_node->left = min_node->right;
            delete min_node;
            min_node = NULL;
        }
    }
    else if(target < cur->key) {
        cur->left = deleteNode(cur->left, target);
    }
    else {
        cur->right = deleteNode(cur->right, target);
    }

    // height update
    updateHeight(cur);
    // check if violation occured
    if(abs(getBF(cur)) > 1) {
        // violation occured
        return restoreBalance(cur);
    }
    else {
        return cur;
    }
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


int AVLTree::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // key already exist
    if(search(_root, key) != NULL) {
        return -1;
    }
    else {
        _root = insertNode(_root, key);
        return 0;
    }
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int AVLTree::remove(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // deleteNode 재귀적으로 구현한 후에 BF 확인
    if(search(_root, key) == NULL) {
        return -1;
    }
    else {
        _root = deleteNode(_root, key);
        return 0;
    }    

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
