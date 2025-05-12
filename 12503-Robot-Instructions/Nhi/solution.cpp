#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Function to move to the left 
void moveLeft(int& x, vector<string>& I)
{
    --x;
    I.push_back("LEFT");
}

// Function to move to the right
void moveRight(int& x, vector<string>& I)
{
    ++x;
    I.push_back("RIGHT");
}


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x = 0; // The initial position
        int n;
        cin >> n;
        cin.ignore();
        vector<string> Ins; // Vector to store all instructions in the order
        for (int i = 0; i < n; i++)
        {
            string Instruction;
            getline(cin, Instruction);
            if (Instruction == "LEFT")
                moveLeft(x, Ins);
            else if (Instruction == "RIGHT")
                moveRight(x, Ins);
            else
            {
                // Extract the number from the string
                string strNum= "";
                for (int i = 0; i < Instruction.size(); i++)
                {
                    if (isdigit(Instruction[i]))
                    {
                        strNum += Instruction[i];
                    }
                }
                int num = stoi(strNum);

                if (Ins[num - 1] == "LEFT") moveLeft(x, Ins);
                else moveRight(x, Ins);  
            }
        }
        cout << x << endl;
    }
    return 0;
}
