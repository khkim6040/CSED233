#pragma once
#include <string>

using namespace std;

struct Node {
    Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
    char value;
    Node *left;
    Node *right;
};

class BinaryTree {
  public:
    BinaryTree() { _root = NULL; };
    ~BinaryTree() {
        delete[] _root;
        _root = NULL;
    };
    void buildFromString(const char *data);

    string preOrder(int node_value);
    string postOrder(int node_value);
    string inOrder(int node_value);
    int getDepth(int node_value);
    bool isReverseComplete();

  private:
    Node *_root;
    Node *_buildFromString(const char *data, int start, int end);
    /////////////////////////////////////////////////////////
    //////  TODO: Add Private members if required ///////////
    Node *GetNode(Node *root, const int &target);
    void preOrderTraversal(Node *node, string &result);
    void postOrderTraversal(Node *node, string &result);
    void inOrderTraversal(Node *node, string &result);
    int findDepth(Node *node, int target, int count);
    bool reverseCompleteChecker(Node *node, bool &end_checker);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
