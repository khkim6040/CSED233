#include <iostream>

using namespace std;

class Instruction {
public:
    void setCommand(string cmd);
    void setValue(int val);
    void setValueStr(string val);

    string getCommand();
    int getValue();
    string getValueStr();

private:
    string command;
    string value_str;
    int value;
};

class InstructionSequence {
public:
    InstructionSequence();
    ~InstructionSequence();

    int getLength();
    Instruction& getInstruction(int index);

    void parseInstructions(const char* arg);
    void printInstructions();

private:
    Instruction* instructions;
    int length;
};


const char* const TASK_1_DEFAULT_ARGUMENT="[('n',4),('r',2),('k',2),('insert',0),('insert',1),('insert',3)]";
const char* const TASK_2_DEFAULT_ARGUMENT="[('n',4),('r',2),('insert',15),('insert',13),('insert',3)]";
const char* const TASK_3_DEFAULT_ARGUMENT="[('A','C'),('A','B'),('A','D'),('B','C'),('B','D'),('B','E'),('B','F'),('C','F'),('C','E'),('End','DFS')]";
const char* const TASK_4_DEFAULT_ARGUMENT="[('A','B'),('A','C'),('D','C'),('C','E'),('B','D'),('E','D')]";
const char* const TASK_5_DEFAULT_ARGUMENT="[('A-B',10),('A-C',3),('B-D',5),('C-B',2),('C-E',5),('A-D',20),('D-E',11),('A','E')]";
const char* const TASK_6_DEFAULT_ARGUMENT="[('A-B',4),('A-F',3),('B-F',6),('B-C',9),('F-E',-2),('C-E',-3),('E-D',6), ('A','D')]";
const char* const TASK_7_DEFAULT_ARGUMENT="[('A-B',3),('A-C',1),('B-C',4),('B-D',1),('C-D',2),('D-E',5),('MST','A')]";
const char* const TASK_8_DEFAULT_ARGUMENT="[('A-B',3),('A-C',1),('B-C',4),('B-D',1),('C-D',2),('D-E',5),('MST','B')]";
