// Project Euler - Problem 9: Special Pythagorean Triplet
// Removes the innermost loop by computing c = 1000 - a - b directly
#include <iostream>
using namespace std;

int main()
{
    for (int a = 1; a < 998; a++)
    {
        for (int b = a + 1; b < 999 - a; b++)
        {
            int c = 1000 - a - b;
            if (c > b && a * a + b * b == c * c)
            {
                cout << a << " " << b << " " << c << "\n";
                cout << "Product: " << (long long)a * b * c << "\n";
                return 0;
            }
        }
    }
    return 0;
}
