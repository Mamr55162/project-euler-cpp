// Project Euler - Problem 3: Largest Prime Factor
// Trial division directly on the target number — no need to sieve up to 600 billion
#include <iostream>
using namespace std;

int main()
{
    long long n = 600851475143LL;
    long long largest = 0;

    // Divide out factor 2
    while (n % 2 == 0)
    {
        largest = 2;
        n /= 2;
    }

    // Try odd factors from 3 upward
    for (long long p = 3; p * p <= n; p += 2)
    {
        while (n % p == 0)
        {
            largest = p;
            n /= p;
        }
    }

    // If n is still > 1, it's a prime factor itself
    if (n > 1)
        largest = n;

    cout << largest << "\n";
    return 0;
}
