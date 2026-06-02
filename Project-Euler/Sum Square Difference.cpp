// Project Euler - Problem 6: Sum Square Difference
// Fixed off-by-one: loop must include 100, i.e. i from 1 to 100 (original started at 0)
#include <iostream>
using namespace std;

int main()
{
    long long sumOfSquares = 0, sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sumOfSquares += (long long)i * i;
        sum += i;
    }
    cout << (sum * sum) - sumOfSquares << "\n";
    return 0;
}
