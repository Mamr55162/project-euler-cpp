
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

int main()
{
    mp::cpp_int sum = 0;
    long long curr = 0;
    for (mp::cpp_int num = 1000; num < 999999; num++)
    {
        curr = 0;
        string number = to_string(num);
        for (int i = 0; i < number.length(); i++)
        {
            curr += pow((number[i] - '0'), 5);
        }

        if (curr == num)
            sum = sum + num;
    }

    cout << sum;
    return 0;
}