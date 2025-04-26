#include <iostream>
using namespace std;

// A function to quickly calculate the area given coordinates
int calculateArea(int x1, int y1, int x2, int y2)
{
    int length = x2 - x1;
    int width = y2 - y1;
    if (length <= 0 || width <= 0)  return 0;
    return length*width;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        const int fieldArea = 10000;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        int stronglySecured = 0;
        int weaklySecured = 0;
        int unsecured = 0;

        // Find the coordinates for the intersection part
        int x_1 = max(x1, x3);
        int y_1 = max(y1, y3);
        int x_2 = min(x2, x4);
        int y_2 = min(y2, y4);

        stronglySecured = calculateArea(x_1, y_1, x_2, y_2); // If there is no intersection part, calculateArea returns 0


        weaklySecured = calculateArea(x1, y1, x2, y2) + calculateArea(x3, y3, x4, y4) - 2*stronglySecured;
        
        unsecured = fieldArea - weaklySecured - stronglySecured;

        cout << "Day " << i + 1 << ": " << stronglySecured << " " << weaklySecured << " " << unsecured << endl;
    }
    return 0;
}
