#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

MaxHeap::MaxHeap() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    heap_size = 0;
    heap_arr = new char[103];
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string MaxHeap::printHeap() {
    string answer;
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for (int i = 1; i <= heap_size; i++) {
        answer.push_back(heap_arr[i]);
        answer.push_back(' ');
    }
    answer.pop_back();

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
    return answer;
}

void MaxHeap::insertKey(string sen) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    // index of root node is '1' not '0'
    // sen.erase(0, 1);
    // sen.pop_back();
    for (auto ele : sen) {
        int cur_index = heap_size + 1;
        heap_arr[cur_index] = ele; // 끝에 넣고 제자리 찾아가게끔
        heap_size++;
        bool flag = false; // 제자리 찾았으면 true
        // 제자리 찾았거나 요소가 하나뿐이면 break
        while (!flag && cur_index > 1) {
            // 부모노드보다 사전상으로 먼저면 swap
            if (ele < heap_arr[cur_index / 2]) {
                heap_arr[cur_index] = heap_arr[cur_index / 2];
                heap_arr[cur_index / 2] = ele;
                cur_index /= 2;
            }
            // 아니라면 제자리 찾음
            else {
                flag = true;
            }
        }
    }
    printHeap();

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void MaxHeap::deleteMax() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    char target = heap_arr[1];
    // 가장 끝 값을 root node로 넣음
    heap_arr[1] = heap_arr[heap_size];
    heap_size--;
    // root node의 위치찾아줌
    maxHeapProp(heap_arr);
    printHeap();

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void MaxHeap::maxHeapProp(char *arr) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here   /////////////
    int cur_index = 1;
    while (cur_index <= heap_size) {
        // 현재 위치에서 자식들보다 알파벳 빠르다면 위치 정해짐
        // 자식이 없을 때
        if (cur_index * 2 > heap_size) {
            break;
        }
        // 왼쪽 자식이 끝 노드이고 알파벳이 느릴 때 때
        else if (cur_index * 2 == heap_size &&
                 arr[cur_index] < arr[cur_index * 2]) {
            break;
        }
        // 두 자식 모두 알파벳이 느릴 때
        else if (arr[cur_index] < arr[cur_index * 2] &&
                 arr[cur_index] < arr[cur_index * 2 + 1]) {
            break;
        }

        // 알파벳 더 빠른 자식이 있다면 가장 빠른 자식과 바꿈
        int next_index = arr[cur_index * 2] > arr[cur_index * 2 + 1]
                             ? cur_index * 2 + 1
                             : cur_index * 2;
        char temp = arr[next_index];
        arr[next_index] = arr[cur_index];
        arr[cur_index] = temp;
        cur_index = next_index;
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}