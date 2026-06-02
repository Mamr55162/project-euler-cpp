// Project Euler - Problem 45: Triangular, Pentagonal, and Hexagonal
// Uses inverse formula checks instead of triple nested loop (O(n^3) -> O(n))
// A number T is pentagonal iff (1 + sqrt(1+24T)) / 6 is a positive integer
// Every hexagonal number is also triangular, so we only need to check hexagonal numbers
#include <iostream>
#include <cmath>
using namespace std;

bool isPentagonal(long long n)
{
    double k = (1.0 + sqrt(1.0 + 24.0 * n)) / 6.0;
    return k > 0 && fabs(k - round(k)) < 1e-9;
}

int main()
{
    // H(n) = n(2n-1); all hexagonal numbers are also triangular.
    // Start from index 144 (first solution T(285)=P(165)=H(143) is known;
    // problem asks for the next one beyond T(285)).
    for (long long n = 144; ; n++)
    {
        long long h = n * (2 * n - 1);
        if (isPentagonal(h))
        {
            cout << h << "\n";
            return 0;
        }
    }
    return 0;
}
