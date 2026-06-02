
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
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
namespace mp = boost::multiprecision;

vector<string> ones = {"NULL", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"NULL", "NULL", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string ten_count(const int &n)
{

    string num = to_string(n);
    if (num.length() > 2)
    {
        throw invalid_argument("Number should be two digits");
    }

    string result = "";
    if (n >= 20)
    {
        result += tens[num[0] - '0'];
        if (num[1] != '0')
        {
            result += ones[num[1] - '0'];
        }
    }
    else if (n < 20 && n != 0)
    {
        result += ones[n];
    }

    return result;
}

string hundred_count(const int &m)
{
    string number = to_string(m);
    if (number.length() > 3)
    {
        throw invalid_argument("Number should be three digits");
    }
    string final = "";
    final += ones[number[0] - '0'];
    final += "hundred";
    const int rem = ((number[1] - '0') * 10) + (number[2] - '0');
    if (rem >= 20)
    {
        final += "and";
        final += ten_count(rem);
    }
    else if (rem < 20 && rem != 0)
    {
        final += "and";
        final += ones[rem];
    }
    else if (rem == 0)
    {
        return final;
    }

    return final;
}

string thousand_count(const int &k)
{
    string numb = to_string(k);
    if (numb.length() > 4)
    {
        throw invalid_argument("Number must be 4 digits");
    }
    string fin = "";
    fin += ones[numb[0] - '0'];
    fin += "thousand";
    const int remainder = (numb[1] - '0') * 100 + (numb[2] - '0') * 10 + (numb[3] - '0');
    if (remainder >= 100)
    {
        fin += hundred_count(remainder);
    }
    else if (remainder == 0)
    {
        return fin;
    }
    else if (remainder < 100 && remainder != 0)
    {
        fin += ten_count(remainder);
    }
    return fin;
}
int main()
{
    vector<string> numbers;
    for (int i = 1; i <= 99; i++)
    {
        numbers.push_back(ten_count(i));
        // cout << ten_count(i) << " ";
    }

    for (int n = 100; n <= 999; n++)
    {
        numbers.push_back(hundred_count(n));
        // cout << hundred_count(n) << " ";
    }

    numbers.push_back(thousand_count(1000));

    int sum = 0;
    for (int p = 0; p < numbers.size(); p++)
    {

        for (char c : numbers[p])
        {
            if (c >= 'a' && c <= 'z')
            {
                sum++;
            }
        }
    }

    cout << sum;
    return 0;
}