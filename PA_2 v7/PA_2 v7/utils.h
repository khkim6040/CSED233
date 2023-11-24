#include <iostream>

using namespace std;

class Instruction {
public:
    void setCommand(string cmd);
    void setValue(string val);

    string getCommand();
    string getValue();

private:
    string command;
    string value;
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


const char* const TASK_2_DEFAULT_ARGUMENT="4(2(3)(1))(6(5))";
const char* const TASK_2_DEFAULT_ARGUMENT_2="inorder";
const int TASK_2_DEFAULT_ARGUMENT_3=2;
const char* const TASK_3_DEFAULT_ARGUMENT="1(2(3(4)))(5)";
const int TASK_3_DEFAULT_ARGUMENT_2=4;
const char* const TASK_4_DEFAULT_ARGUMENT="1(2()(5))(3(6)(7))";
const char* const TASK_5_DEFAULT_ARGUMENT="[('insert',\"cab\")]";
const char* const TASK_6_DEFAULT_ARGUMENT="[('insert',\"apple\"),('delMax',NULL)]";
