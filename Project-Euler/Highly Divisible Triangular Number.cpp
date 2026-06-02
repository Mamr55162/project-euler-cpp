
#include <stdexcept>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

vector<long long> trnum(900000);

long long triangle_num(long long n)
{

    return (n * (n + 1)) / 2;
}

int countDivisors(long long num)
{
    if (num == 1)
        return 1;
    int count = 1;
    for (long long p = 2; p * p <= num; p++)
    {
        if (num % p == 0)
        {
            int exponent = 0;
            while (num % p == 0)
            {
                num /= p;
                exponent++;
            }
            count *= (exponent + 1);
        }
    }
    if (num > 1)
        count *= 2; // Remaining prime factor
    return count;
}

int main()
{
    for (long long j = 100000; j <= 999999; j++)
    {
        trnum.push_back(triangle_num(j));
    }

    for (long long n = 1;; n++)
    {
        long long T_n = n * (n + 1) / 2; // Triangular number
        int divisors = countDivisors(T_n);
        if (divisors > 500)
        {
            cout << "Found: " << T_n << " (T_" << n << ")";
            cout << " with " << divisors << " divisors" << endl;
            break;
        }
    }
    return 0;
}