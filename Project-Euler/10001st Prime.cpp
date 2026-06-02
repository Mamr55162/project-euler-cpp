// Project Euler - Problem 7: 10001st Prime
// Uses proper Sieve of Eratosthenes with a boolean array (no erasing from vector)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int LIMIT = 200000; // Sufficient upper bound for the 10001st prime
    vector<bool> isPrime(LIMIT, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; (long long)p * p < LIMIT; p++)
    {
        if (isPrime[p])
            for (int multiple = p * p; multiple < LIMIT; multiple += p)
                isPrime[multiple] = false;
    }

    int count = 0;
    for (int n = 2; n < LIMIT; n++)
    {
        if (isPrime[n])
        {
            count++;
            if (count == 10001)
            {
                cout << n << "\n";
                return 0;
            }
        }
    }
    return 0;
}
