#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// create a reference table for power of 2
// we need a data type that is large enough to handle 2^100 to we use __int128
// however, __int128 is not a fundamental type so we should declare a function that
// reads the input as a line of text and return the number

// build a table for power of 2 for reference for the algorithm
static __int128 power_of_two[101] = {0};
int pegs[3] = {0};


// overload an operator for __int128
// ostream& operator << (ostream& output, __int128 n)
// {
//     if (n == 0) return output << "0";
//     string s = "";
//     while (n > 0)
//     {
//         s += (n % 10) + '0';
//         n /= 10;
//     }
//     reverse(s.begin(), s.end());
//     output << s;
//     return output;
// }

// overload input operator for __int128
istream& operator >> (istream& input, __int128& n)
{
    // take input as a string
    string s = "";
    input >> s;
    // reset the variable to 0
    n = 0;
    // work through each digit to add up the number
    // since n is of __int 128 type so
    // it can store more data thatn int or long long
    for (int i = 0; i < s.size(); i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    // return input for cascading (cin >> n >> m)
    return input;
}

// update the number of disk based on the number of moves so far
void towerOfHanoi(int disk, int start, int end, __int128 move)
{
    // base case
    if (disk == 1)
    {
        // move == 0 means the disk has not been moved to the dest yet
        if (move == 0) ++pegs[start];
        else ++pegs[end];
        return;
    }
    int aux = 3 - start - end;
    // the logic behind this is: we first need to move the largest disk from start to end (considering the largest is the nth disk)
    // but in order to do that, we need to move the top n - 1 disks from start to auxiliary
    // but moving n - 1 disks itself is also a new Tower-Of-Hanoi problem in which the start is the start and the end is auxiliary
    // so we the complexity of the smaller problem is 2^(n - 1) - 1
    // then we move the largest disk from start to end consuming 1 move
    // so we have the comparison like below 
    // in case the the current move is largest the number of moves needed to move the
    // largest disk from start to end
    if (move >= power_of_two[disk - 1]) // thanks to the table we built earlier, we don't need to recalculate everyting everytime we have a new test case
    {
        // add that base disk to the source
        pegs[end]++;
        // exhaust the number of moves
        move -= power_of_two[disk - 1];
        // this is where we bring back the algorithm of the Tower-Of-Hanoi problem
        // moving n - 1 disks from aux to end
        towerOfHanoi(disk - 1, aux, end, move);
    }
    // in case the number of move is not enough
    else
    {
        // add that base disk to the source because it has not been moved away yet
        pegs[start]++;
        // continue the simulation of the Tower-Of-Hanoi problem
        towerOfHanoi(disk - 1, start, aux, move);
    }
}




int main()
{
    power_of_two[0] = 1;
    for (int i = 1; i < 101; i++)
    {
        power_of_two[i] = power_of_two[i - 1] * 2;
    }
    int n;
    __int128 m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < 3; i++)
        {
            pegs[i] = 0;
        }
        towerOfHanoi(n, 0, 2, m);
        // condition check for odd and even number of disks
        // for the even number of disks
        // the order of start aux end aligns with the order of 0 1 2 (considering the very first move we make is moving the very top disk to the next peg, and then we continue the sequence of the top most disk as 012012)
        // note that the algorithm already inherently takes care of the order
        // but this won't asure the 012012 movement pattern of the top most disk
        // so in order to maintain this movement while correctly reflect the number of disks
        // we assume that the destination of the stack in case the number of disks is odd
        // is the middle peg
        if (n % 2 == 0)
        {
            cout << pegs[0] << ' ' << pegs[1] << ' ' << pegs[2] << endl;
        }
        // but for the odd number disks the order of aux and end pegs are reveresed
        // refer to a visual aid web to know more about this
        else
        {
            cout << pegs[0] << ' ' << pegs[2] << ' ' << pegs[1] << endl;
        }
    }    
    return 0;
}