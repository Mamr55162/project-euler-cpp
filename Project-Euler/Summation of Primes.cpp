// Project Euler - Problem 10: Summation of Primes
// Uses a proper boolean sieve instead of erasing from a vector (which is O(n^2))
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int LIMIT = 2000000;
    vector<bool> isPrime(LIMIT, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; (long long)p * p < LIMIT; p++)
        if (isPrime[p])
            for (int multiple = p * p; multiple < LIMIT; multiple += p)
                isPrime[multiple] = false;

    long long sum = 0;
    for (int i = 2; i < LIMIT; i++)
        if (isPrime[i])
            sum += i;

    cout << sum << "\n";
    return 0;
}
