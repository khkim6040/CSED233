#include "hash_function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int BinaryMidSquareHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int count = this->index_size;
    int index = 0;
    long long flag = pow(2, this->key_size-1+this->index_size/2);
    long long square_key = key*key;
    while(count) {
        if(square_key & flag) {
            index += pow(2, count-1);
        }
        flag /= 2;
        count--;
    }
    return index;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int DigitFoldingHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int result = 0;
    int flag = pow(2, key_size-1);
    while(flag) {
        if(key & flag) {
            result++;
        }
        flag /= 2;
    }
    return result;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int MultiplicationHash::hashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    long double frac = (key%10)*A;
    int result = floor(frac*pow(2, index_size));
    return result;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
