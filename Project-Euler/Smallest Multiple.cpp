// Project Euler - Problem 5: Smallest Multiple
// Uses LCM (Least Common Multiple) via GCD — runs instantly instead of brute-forcing billions
#include <iostream>
#include <numeric>   // std::gcd (C++17)
using namespace std;

int main()
{
    long long result = 1;
    for (int i = 2; i <= 20; i++)
        result = result / __gcd(result, (long long)i) * i; // lcm(result, i)

    cout << result << "\n";
    return 0;
}
