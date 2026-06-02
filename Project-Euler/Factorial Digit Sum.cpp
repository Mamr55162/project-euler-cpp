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

string multiply(string num, int multiplier)
{
    int carry = 0;
    for (char &c : num)
    {
        int digit = (c - '0') * multiplier + carry;
        c = (digit % 10) + '0';
        carry = digit / 10;
    }
    while (carry > 0)
    {
        num.push_back((carry % 10) + '0');
        carry /= 10;
    }
    return num;
}

string factorial(int n)
{
    string result = "1";
    for (int i = 2; i <= n; ++i)
    {
        result = multiply(result, i);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    const string number = factorial(100);
    long long sum = 0;
    for (int j = 0; j < number.length(); j++)
    {
        sum += (number[j] - '0');
    }
    cout << sum;

    return 0;
}