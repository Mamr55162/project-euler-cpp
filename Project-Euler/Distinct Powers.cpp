#include <set>
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
    set<mp::cpp_int> arr;
    for (mp::cpp_int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {

            arr.insert(pow(a, b));
        }
    }
    cout << arr.size();

    return 0;
}