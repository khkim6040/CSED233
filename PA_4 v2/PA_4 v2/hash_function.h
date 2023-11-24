#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class BinaryMidSquareHash {

public:
    BinaryMidSquareHash(int n, int r) : key_size(n), index_size(r) { };

    int hashing(int key);

private:
    int key_size;
    int index_size;

    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};

class DigitFoldingHash {

public:
    DigitFoldingHash(int n, int r) : key_size(n), index_size(r) { };

    int hashing(int key);

private:
    int key_size;
    int index_size;

    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};

class MultiplicationHash {

public:
    MultiplicationHash(int n, int r) : key_size(n), index_size(r) { };

    int hashing(int key);

private:
    const double A = 0.1;
    int key_size;
    int index_size;

    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};