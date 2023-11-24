#include "tree.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
    if (start > end)
        return -1;

    string s;

    for (int i = start; i <= end; i++) {

        // if open parenthesis, push it
        if (str[i] == '(')
            s.push_back(str[i]);

        // if close parenthesis
        else if (str[i] == ')') {
            if (s.back() == '(') {
                s.pop_back();

                if (!s.length())
                    return i;
            }
        }
    }
    // if not found return -1
    return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
    if (start > end)
        return NULL;

    Node *root = new Node(data[start]);
    int index = -1;

    if (start + 1 <= end && data[start + 1] == '(')
        index = findIndex(data, start + 1, end);

    if (index != -1) {
        root->left = _buildFromString(data, start + 2, index - 1);
        root->right = _buildFromString(data, index + 2, end - 1);
    }
    return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
    Node *root = _buildFromString(data, 0, strlen(data) - 1);
    _root = root;
}

string BinaryTree::preOrder(int node_value) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node *start_node = GetNode(_root, node_value);
    if (start_node == NULL) {
        return "error";
    }
    string ans;
    preOrderTraversal(start_node, ans);
    if (!ans.empty()) {
        ans.pop_back();
    }
    return ans;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder(int node_value) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node *start_node = GetNode(_root, node_value);
    if (start_node == NULL) {
        return "error";
    }
    string ans;
    postOrderTraversal(start_node, ans);
    if (!ans.empty()) {
        ans.pop_back();
    }
    return ans;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder(int node_value) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node *start_node = GetNode(_root, node_value);
    if (start_node == NULL) {
        return "error";
    }
    string ans;
    inOrderTraversal(start_node, ans);
    if (!ans.empty()) {
        ans.pop_back();
    }
    return ans;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int BinaryTree::getDepth(int node_value) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int target_depth = findDepth(_root, node_value, 0);
    return target_depth;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

bool BinaryTree::isReverseComplete() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    bool end_checker = false;
    return reverseCompleteChecker(_root, end_checker);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    return false;
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

Node *BinaryTree::GetNode(Node *root, const int &target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->value - '0' == target) {
        return root;
    }

    Node *node = GetNode(root->left, target);
    if (node == NULL) {
        node = GetNode(root->right, target);
    }
    return node;
}

void BinaryTree::preOrderTraversal(Node *node, string &result) {
    if (node == nullptr) {
        return;
    }
    result.push_back(node->value);
    result.push_back(' ');
    preOrderTraversal(node->left, result);
    preOrderTraversal(node->right, result);
}

void BinaryTree::postOrderTraversal(Node *node, string &result) {
    if (node == nullptr) {
        return;
    }
    postOrderTraversal(node->left, result);
    postOrderTraversal(node->right, result);
    result.push_back(node->value);
    result.push_back(' ');
}

void BinaryTree::inOrderTraversal(Node *node, string &result) {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(node->left, result);
    result.push_back(node->value);
    result.push_back(' ');
    inOrderTraversal(node->right, result);
}

int BinaryTree::findDepth(Node *node, int target, int count) {
    if (node == NULL) {
        return -1;
    }
    if (node->value - '0' == target) {
        return count;
    }

    int depth = findDepth(node->left, target, count + 1);
    if (depth == -1) {
        depth = findDepth(node->right, target, count + 1);
    }
    return depth;
}

bool BinaryTree::reverseCompleteChecker(Node *node, bool &end_checker) {
    // 빈 노드거나 자식이 없으면 reverseComplete함
    if (!node || (!node->left && !node->right)) {
        return true;
    }
    // 현재 depth가 full이 아닌데 자식 노드가 있는 경우 -> complete가 아님
    if (end_checker && (node->left || node->right)) {
        return false;
    }
    // 오른쪽 자식이 없는데 왼쪽 자식이 있으면 reverseComplete 아님
    if (!node->right && node->left) {
        return false;
    }
    // 왼쪽 자식이 없다면 complete아님을 알림
    if (!node->left) {
        end_checker = true;
    }
    // 재귀적으로 양쪽 자식 탐색
    bool check_right = reverseCompleteChecker(node->right, end_checker);
    bool check_left = reverseCompleteChecker(node->left, end_checker);
    // 두 쪽 모두 조건 만족해야 함
    return check_right && check_left;
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
