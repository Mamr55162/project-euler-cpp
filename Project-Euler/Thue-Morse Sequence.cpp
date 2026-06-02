#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int T(int n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 0)
        return T(n/2);
    else
        return 1 - T((n-1)/2);
}

bool A(double n)
{
    string str = to_string(n);
    vector<double> seq(100000);
    for (int i = 0; i < 100000; i++)
    {
        seq[i] = T(i);
    }
    if (str.length() <= 4)
    {
        int i = 0;
        while (i < seq.size() - 16)
        {
            double decimal = 0;
            for (int j = i; j < 16+i; j++)
            {
                if (seq[j] == 1)
                    decimal += pow(2, seq.size() - 1 - j);
                if (decimal == n)
                    return true;
            }
            i++;
        }
    }
    return false;
}

int main()
{

    cout << A(18);

    return 0;
}