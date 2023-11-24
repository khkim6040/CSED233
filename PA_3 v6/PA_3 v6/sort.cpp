#include "sort.h"
#include <iostream>
#include <fstream>
#include <string>


sortAlg::sortAlg() {
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
    temp = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}


void sortAlg::insertionSort(ofstream &fout) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////


    for (int i = 0; i < arr_size - 1; i++) {
        int j = i+1;
        int key = arr[j];
        while(j>0 && arr[j-1]>key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
        printArray(fout); // DO NOT ERASE THIS LINE
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::merge(int left, int right, int &count) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int i, j, k;
    int mid = left + (right-left)/2;
    i = left;
    j = mid+1;
    k = left;
    while(i<=mid && j<=right) {
        if(arr[j] < arr[i]) {
            temp[k++] = arr[j++];
            count++;
        }
        else {
            temp[k++] = arr[i++];
        }
    }

    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=right) {
        temp[k++] = arr[j++];
    }

    for(int i=left; i<=right; i++) {
        arr[i] = temp[i];
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::mergeSort(ofstream &fout, int left, int right, int &count) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (left < right) {
        int mid = left + (right-left)/2;
        mergeSort(fout, left, mid, count);
        mergeSort(fout, mid+1, right, count);
        merge(left, right, count);
    
        printArray(fout);// DO NOT ERASE THIS LINE

    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

}
