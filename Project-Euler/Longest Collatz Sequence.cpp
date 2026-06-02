// Project Euler - Problem 14: Longest Collatz Sequence
// Memoization (cache) avoids recomputing Collatz lengths for numbers already seen
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, int> memo;

int collatz(long long n)
{
    if (n == 1) return 1;

    auto it = memo.find(n);
    if (it != memo.end()) return it->second;

    int len = 1 + collatz((n % 2 == 0) ? n / 2 : 3 * n + 1);
    memo[n] = len;
    return len;
}

int main()
{
    int bestLen = 0;
    long long bestNum = 0;

    for (long long i = 1; i < 1000000; i++)
    {
        int len = collatz(i);
        if (len > bestLen)
        {
            bestLen = len;
            bestNum = i;
        }
    }

    cout << "Starting number: " << bestNum << "\n";
    cout << "Chain length:    " << bestLen << "\n";
    return 0;
}
