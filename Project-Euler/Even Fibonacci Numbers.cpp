// Problem 2 : Even Fibonacci Numbers
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
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

vector<long long> fibo;

long long fib(int n)
{
    if (n <= 0)
        return 0;
    fibo.resize(n + 1);
    fibo[0] = 0; // fib(0) = 0 (even)
    fibo[1] = fibo[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
}

int main()
{

    fib(33);
    cout << fibo[33] << "\n";

    long long sum = 0;
    for (int j = 3; j < fibo.size(); j += 3)
    {
        sum += fibo[j];
    }
    cout << sum;
    return 0;
}
