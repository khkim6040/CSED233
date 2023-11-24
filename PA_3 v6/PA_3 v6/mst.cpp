#include "mst.h"
#include <iostream>
#include <string>

using namespace std;

string MultiWayTree::preOrder() {
	string output;
	_preOrder(output, _root);
	if (!output.empty())
		output.pop_back();
	return output;
}

void MultiWayTree::_preOrder(string& output, MultiNode *cur) {
	if(cur == NULL)
		return;
	// std::cout << cur << ' ' << cur->key1 << ' ' << cur->key2 << '\n';
	output.append(cur->print_key());
	output.append(" ");
	_preOrder(output, cur->left);
	_preOrder(output, cur->middle);
	_preOrder(output, cur->right);
}

int MultiWaySearchTree::insert(int key) {
	/////////////////////////////////////////////////////////
	//////////  TODO: Implement From Here      //////////////
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

int MultiWaySearchTree::remove(int key) {
	/////////////////////////////////////////////////////////
	//////////  TODO: Implement From Here      //////////////
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

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

MultiNode* MultiWaySearchTree::search(MultiNode* cur, const int &target) {
	if(cur==NULL) {
		return NULL;
	}

	if(target==cur->key1 || target==cur->key2) {
		return cur;
	}

	if(cur->key1 && cur->key2) {
		if(target < cur->key1) {
			return search(cur->left, target);
		}
		else if(target < cur->key2) {
			return search(cur->middle, target);
		}
		else if(target > cur->key2) {
			return search(cur->right, target);
		}
	}
	else if(cur->key1) {
		if(target<cur->key1) {
			return search(cur->left, target);
		}
		else {
			return search(cur->middle, target);
		}
	}
	else if(cur->key2) {
		if(target < cur->key2) {
			return search(cur->middle, target);
		}
		else if(target > cur->key2) {
			return search(cur->right, target);
		}
	}
	
    return NULL;
}

MultiNode* MultiWaySearchTree::insertNode(MultiNode* cur, const int &key) {
	// when reached empty node, make new node
	if(cur==NULL) {
		MultiNode* temp = new MultiNode;
		temp->key1 = key;
		return temp;
	}

	// If find empty node, then put key in that node
	if(cur->key1*cur->key2 == 0) {
		if(cur->key1==0 && cur->key2==0) {
			cur->key1 = key;
		}
		else if(cur->key1) {
			int temp = cur->key1;
			cur->key1 = min(temp, key);
			cur->key2 = max(temp, key);
		}
		else {
			int temp = cur->key2;
			cur->key1 = min(temp, key);
			cur->key2 = max(temp, key);
		}
	}
	// If the node is full, find proper child node to insert 
	else {
		if(key < cur->key1) {
			cur->left = insertNode(cur->left, key);
		}
		else if(key < cur->key2) {
			cur->middle = insertNode(cur->middle, key);
		}
		else {
			cur->right = insertNode(cur->right, key);
		}
	}

	return cur;
}

MultiNode* MultiWaySearchTree::deleteNode(MultiNode* cur, const int &target) {
	// cur->key1이 target일 때. key1을 삭제
	if(cur->key1 == target) {
        int replaced_value = findDeletedValue(cur, 1);
        // key1 아래 subtree가 없을 때
        if(replaced_value == -1) {
			cur->key1 = 0;
			// key2 없다면 node 삭제해야 함
			if(!cur->key2) {
				delete cur;
				cur = NULL;
			}
        }
        else {
            cur->key1 = replaced_value;
            
        }
	}
	// key2와 같을 때
	else if(cur->key2 == target) {
        int replaced_value = findDeletedValue(cur, 2);
        if(replaced_value == -1) {
			cur->key2 = 0;
			// key2 없다면 node 삭제해야 함
			if(!cur->key1) {
				delete cur;
				cur = NULL;
			}
        }
        else {
            cur->key2 = replaced_value;
        }
    }
	// 노드의 key 중 일치하는 값이 없을 때. 계속 탐색
	else {
		if(cur->key1 && cur->key2) {
			if(target < cur->key1) {
				cur->left = deleteNode(cur->left, target);
			}
			else if(target < cur->key2) {
				cur->middle = deleteNode(cur->middle, target);
			}
			else {
				cur->right = deleteNode(cur->right, target);
			}
		}
		else if(cur->key1) {
			if(target < cur->key1) {
				cur->left = deleteNode(cur->left, target);
			}
			else {
				cur->middle = deleteNode(cur->middle, target);
			}
		}
		else if(cur->key2) {
			if(target < cur->key2) {
				cur->middle = deleteNode(cur->middle, target);
			}
			else {
				cur->right = deleteNode(cur->right, target);
			}			
		}
		else {
			// 둘 다 없는 경우는 없음
			// 왜냐? search로 삭제하려는 값이 있는지 확인했으니까
		}
	}

	return cur;
}

// 지워지는 값을 대체할 값 리턴. right subtree의 최솟값->left subtree의 최댓값의 우선순위
// key_pos = key1이 지워지냐 key2가 지워지냐에 따라 subtree 바뀌기때문에 정보전달
// 만약 temp 노드가 leaf node라면 연결 끊음
int MultiWaySearchTree::findDeletedValue(MultiNode* root, int key_pos) {
        MultiNode* parent = root;
        // 우선적으로 오른쪽 subtree로 temp 설정
        MultiNode* temp = key_pos==1 ? parent->middle : parent->right;
        int target = -1;
        bool flag = true;
        // To know which direction temp node chose. 0->left, 1->middle 
        int direction = key_pos==1 ? 2 : 3; 
        // 인자로 받은 root node가 leaf 노드일 때. 삭제할지 말지는 delete함수에서 함
        if(key_pos==1 && !parent->left && !parent->middle) {
            return -1;
        }
        else if(key_pos==2 && !parent->right && !parent->middle) {
            return -1;
        }

        // right subtree가 존재할 때 해당 tree의 최솟값 찾기
        if(temp) {
            while(flag) {
                // 왼쪽으로 쭉 내려가고
                while(temp->left) {
                    parent = temp;
                    temp = temp->left;
                    direction = 1;
                }
                // 왼쪽 막혔을 때 왼쪽 값이 없고 middle이 있다면 더 작은값 있음
                if(!temp->key1 && temp->middle) {
                    parent = temp;
                    temp = temp->middle;
                    direction = 2;
                }
                else {
                    flag = false;
                }
            }
            // set Min value
            if(temp->key1) {
                target = temp->key1;
                temp->key1 = 0;
            }
            else {
                target = temp->key2;
                temp->key2 = 0;
            }
            // temp key를 0으로 바꾼 후 key 없고 leaf노드이면 삭제 
            if(!temp->key1 && !temp->key2 && !temp->left && !temp->middle && !temp->right) {
                if(direction==1) {
                    parent->left = NULL;
                }
                else if(direction==2) {
                    parent->middle = NULL;
                }
                else {
                    parent->right = NULL;
                }
                delete temp;
                temp = NULL;
            }
            // temp의 key를 대체할 수 있는 subtree를 갖고있다면 subtree에서 또 값 들고 삭제된 temp의 key 채워야함 
            else {
                if(direction==1) {
                    parent->left = deleteNode(temp, 0);
                }
                else if(direction==2) {
                    parent->middle = deleteNode(temp, 0);
                }
                else {
                    parent->right = deleteNode(temp, 0);
                }
            }
        }
        // 오른쪽 subtree가 없다면 왼쪽 subtree의 최댓값 반환
        else {
            temp = key_pos==1 ? parent->left : parent->middle;
            direction = key_pos==1 ? 1 : 2;
            while(flag) {
                while(temp->right) {
                    parent = temp;
                    temp = temp->right;
                    direction = 3;
                }
                if(!temp->key2 && temp->middle) {
                    parent = temp;
                    temp = temp->middle;
                    direction = 2;
                }
                else {
                    flag = false;
                }
            }
            // 해당 노드의 최댓값을 target으로
            if(temp->key2) {
                target = temp->key2;
                temp->key2 = 0;
            }
            else {
                target = temp->key1;
                temp->key1 = 0;
            }
            // temp가 키를 하나만 가진 leaf node라면 삭제
            if(!temp->key1 && !temp->key2 && !temp->left && !temp->middle && !temp->right) {
                if(direction==1) {
                    parent->left = NULL;
                }
                else if(direction==2) {
                    parent->middle = NULL;
                }
                else {
                    parent->right = NULL;
                }
                delete temp;
                temp = NULL;
            }
            else {
                if(direction==1) {
                    parent->left = deleteNode(temp, 0);
                }
                else if(direction==2) {
                    parent->middle = deleteNode(temp, 0);
                }
                else {
                    parent->right = deleteNode(temp, 0);
                }
            }
        }

        return target;
    }


///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
