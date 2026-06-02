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
    mp::cpp_int total = 0;

    for (int i = 1; i <= 1000; i++)
    {
        mp::cpp_int term = 1;
        for (int j = 0; j < i; j++)
        {
            term *= i;
        }
        total += term;
    }
    cout << total;

       return 0;
}