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

    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int DABSTree::remove(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    return 0;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////