#include <iostream>
#include <fstream>
#include <string>
#include "hash_function.h"
#include "hash_table.h"

using namespace std;


BucketHashTable::BucketHashTable(int table_size, int bucket_size, BinaryMidSquareHash *hf) : table_size(table_size), bucket_size(bucket_size) {
    this->hf = hf;
    this->table = new int[this->table_size * this->bucket_size];
    this->overflow = new int[this->table_size];
    this->table_states = new TableState[this->table_size * this->bucket_size]{EMPTY};
    this->overflow_states = new TableState[this->table_size]{EMPTY};

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

BucketHashTable::~BucketHashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] this->table;
    delete[] this->overflow;
    delete[] this->table_states;
    delete[] this->overflow_states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BucketHashTable::print_table(ostream &out) {
    
    out << "Hash table" << endl;
    int state;
    for (int i=0; i < table_size; i++) {
        out << i << ": ";
        for (int j = 0; j < bucket_size; j++) {
            state = table_states[i * bucket_size + j];
            if (state == EMPTY)
                out << "empty";
            else if (state == DELETED)
                out << "deleted";
            else if (state == OCCUPIED)
                out << table[i * bucket_size + j];
            else
                out << "unknown state";
            if (j < bucket_size - 1)
                out << ",";
        }
        out << endl;
    }
    out << "----------" << endl << "Overflow" << endl;
    for (int i=0; i < table_size; i++) {
        out << i << ": ";
        state = overflow_states[i];
        if (state == EMPTY)
            out << "empty" << endl;
        else if (state == DELETED)
            out << "deleted" << endl;
        else if (state == OCCUPIED)
            out << overflow[i] << endl;
        else
            out << "unknown state" << endl;
    }
}

void BucketHashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void BucketHashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

DoubleHashTable::DoubleHashTable(int table_size, MultiplicationHash *hf_1, DigitFoldingHash *hf_2) : table_size(table_size) {
    this->hf_1 = hf_1;
    this->hf_2 = hf_2;
    this->table = new int[this->table_size];
    this->states = new TableState[this->table_size]{EMPTY};

    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

DoubleHashTable::~DoubleHashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] this->table;
    delete[] this->states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void DoubleHashTable::print_table(ostream &out) {
    for (int i=0; i < this->table_size; i++) {
        out << i << ": ";
        int state = this->states[i];
        if (state == EMPTY)
            out << "empty" << endl;
        else if (state == DELETED)
            out << "deleted" << endl;
        else if (state == OCCUPIED)
            out << this->table[i] << endl;
        else
            out << "unknown state" << endl;
    }
}

void DoubleHashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void DoubleHashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
