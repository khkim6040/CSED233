#pragma once
#include <string>

using namespace std;

class BTree {
public:

    /////////////////////////////////////////////////////////
    //////  TODO: Implement BTree class, Add public members if required ///////////
    
    BTree(int M) {
        order = M;
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    
    int has_elem(int key);
    int insert_elem(int key);
    int delete_elem(int key);
    string postOrder();

    
private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int order;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
