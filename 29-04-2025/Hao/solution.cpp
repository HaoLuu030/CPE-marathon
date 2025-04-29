#include <iostream>
#include <string>
using namespace std;

// function to handle moving
void move(int& position, string instruction)
{
    if (instruction == "LEFT") --position;
    else ++position;
}

int main()
{
    int test_case, instructions, position;
    string instruction;
    cin >> test_case;
    // loop through test case
    for (int i = 0; i < test_case; i++)
    {
        // reset position to 0;
        position = 0;
        cin >> instructions;
        // clear buffer to "prepare" for getline
        cin.ignore();
        // the list to keep track of instructions
        string instruction_list[instructions];
        // loop through intructions
        for (int j = 0; j < instructions; j++)
        {
            getline(cin, instruction);
            // case handling for instructions
            if (instruction == "LEFT" || instruction == "RIGHT")
            {
                move(position, instruction);
                // save the instruction in an array
                instruction_list[j] = instruction;
            }
            else
            {
                string index = "";
                // get the order of position
                // from input text
                for (int i = 8; i < instruction.size(); i++)
                    index += instruction[i];
                string repeated_instruction = instruction_list[stoi(index) - 1];
                move(position, repeated_instruction);
                // save the instruction in an array
                instruction_list[j] = repeated_instruction;
            }
        }
        cout << position << endl;
    }
}