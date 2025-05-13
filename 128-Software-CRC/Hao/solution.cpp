#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int g = 34943;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;

        int sum = 0;
        for (char ch : line) {
            sum = (sum * 256 + (unsigned char)ch) % g;
        }

        sum = (sum * 256) % g;
        sum = (sum * 256) % g;

        int crc = (g - sum) % g;
        printf("%02X %02X\n", crc >> 8, crc & 0xFF);
    }
}
