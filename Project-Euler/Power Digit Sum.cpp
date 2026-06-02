
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

string powerOfTwo(int exponent)
{
    string result = "1";
    for (int i = 0; i < exponent; ++i)
    {
        int carry = 0;
        for (char &c : result)
        {
            int digit = (c - '0') * 2 + carry;
            c = (digit % 10) + '0';
            carry = digit / 10;
        }
        if (carry > 0)
        {
            result.push_back(carry + '0');
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{

    long long sum = 0;
    string num = powerOfTwo(1000);
    for (int j = 0; j < num.size(); j++)
    {
        sum += num[j] - '0';
    }
    cout << sum;

    return 0;
}