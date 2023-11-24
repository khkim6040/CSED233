#pragma once
#include <string>

using namespace std;

class MultiNode {
public:
    MultiNode() : key1(0), key2(0), height(0), left(NULL), middle(NULL), right(NULL) {}
    int key1;
    int key2;
    int height;
    MultiNode *left;
    MultiNode *middle;
    MultiNode *right;
    /* Add public members if required*/
    string print_key() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    string keys = "";
    if(key1 && key2) {
        keys += to_string(key1);
        keys += ' ';
        keys += to_string(key2);
    }
    else if(key1) {
        keys += to_string(key1);
    }
    else if(key2) {
        keys += to_string(key2);
    }
        
    return keys;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
    };
};

class MultiWayTree {
public:
    MultiWayTree() { _root = NULL; };
    ~MultiWayTree() {
        delete[] _root;
        _root = NULL;
    };
    string preOrder();

protected:
    MultiNode *_root;

private:
    void _preOrder(string& output, MultiNode *cur);
};

class MultiWaySearchTree: public MultiWayTree {
public:
    MultiWaySearchTree() { };
    ~MultiWaySearchTree() { };

    int insert(int key);
    int remove(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    MultiNode* search(MultiNode* cur, const int &target);
    MultiNode* insertNode(MultiNode* cur, const int &key);
    MultiNode* deleteNode(MultiNode* cur, const int &target);
    int min(int a, int b) {return a<b ? a : b;}
    int max(int a, int b) {return a>b ? a : b;}
    int findDeletedValue(MultiNode* root, int key_pos);

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
