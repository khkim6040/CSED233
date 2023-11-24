#pragma once
#include <iostream>
#include <string>
using namespace std;

class MaxHeap {

  public:
    MaxHeap();

    int heap_size;

    void maxHeapProp(char *arr);
    void insertKey(string sen);
    void deleteMax();
    string printHeap();
    /////////////////////////////////////////////////////////
    //////  TODO: Add Public members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

  private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add Private members if required ///////////
    char *heap_arr;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
