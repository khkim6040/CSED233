#include <iostream>

using namespace std;

class Instruction {
public:
    void setCommand(string cmd);
    void setValue(int val);

    string getCommand();
    int getValue();

private:
    string command;
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

const char* const TASK_1_DEFAULT_ARGUMENT="[('insert',42),('insert',20),('insert',17),('insert',13),('insert',28),('insert',14),('insertionSort',NULL)]";
const char* const TASK_2_DEFAULT_ARGUMENT="[('insert',5),('insert',6),('insert',4),('insert',3),('insert',2),('insert',1),('insert',10),('insert',7),('mergeSort',NULL)]";
const char* const TASK_3_DEFAULT_ARGUMENT="[('insert',3),('insert',5),('insert',5),('insert',9),('remove',9)]";
const char* const TASK_4_DEFAULT_ARGUMENT="[('insert',4),('insert',6),('insert',0),('remove',7)]";
const char* const TASK_5_DEFAULT_ARGUMENT="[('insert',4),('insert',6),('insert',6),('insert',7),('remove',7)]";
const char* const TASK_6_DEFAULT_ARGUMENT="[('M',4),('key',1),('key',2),('key',3),('key',4)]";

