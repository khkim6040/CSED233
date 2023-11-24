#include "tree.h"
#include "bst.h"
#include "dabst.h"
#include <iostream>
#include <string>

using namespace std;

string DABSTree::inOrder() {
  string output;
  _inOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

string DABSTree::preOrder() {
  string output;
  _preOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}
  
void DABSTree::_inOrder(string& output, Node *cur) {
  if(cur == NULL)
      return;
  _inOrder(output, cur->left);
  output.append(cur->print_key());
  output.append("(");
  output.append(cur->print_count());
  output.append(")");
  output.append(" ");
  _inOrder(output, cur->right);
}

void DABSTree::_preOrder(string& output, Node *cur) {
  if(cur == NULL)
      return;
  output.append(cur->print_key());
  output.append("(");
  output.append(cur->print_count());
  output.append(")");
  output.append(" ");
  _preOrder(output, cur->left);
  _preOrder(output, cur->right);
}

int DABSTree::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if(_root == NULL) {
        _root = new Node(key);
    }
    else {
        Node *cur = _root;
        while(true) {
            if(key < cur->key) {
                if(cur->left == NULL) {
                    Node *node = new Node(key);
                    cur->left = node;
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else if(key > cur->key) {
                if(cur->right == NULL) {
                    Node *node = new Node(key);
                    cur->right = node;
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
            else {
                cur->count++;
                break;
            }
        }

    }
    return 0;
}
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////

int DABSTree::remove(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // key와 _root 대소관계에 따라 deleteNode 호출
    Node* pos = find(_root, key);
    if(pos == NULL) {
        return -1;
    }
    else {
        // 삭제
        if(pos->count > 1) {
            pos->count--;
        }
        else {
            _root = deleteNode(_root, key);
        }
        return 0;
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
// 재귀적으로 찾아들어감. 
Node* DABSTree::find(Node* cur, const int &target) {
    if(cur == NULL) {
        return NULL;
    }
    else {
        if(target < cur->key) {
            return find(cur->left, target);
        }
        else if(target > cur->key) {
            return find(cur->right, target);
        }
        else {
            return cur;
        }
    }
}

Node* DABSTree::deleteNode(Node* cur, const int &target) {
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
    return cur;
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////