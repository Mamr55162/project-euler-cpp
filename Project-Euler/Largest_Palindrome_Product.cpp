
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

bool isPalindrome(int num)
{
    string s = to_string(num);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main()
{
    int max_palindrome = 0;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = i; j <= 999; j++)
        {
            int product = i * j;
            if (isPalindrome(product) && product > max_palindrome)
            {
                max_palindrome = product;
            }
        }
    }
    cout << "Largest palindrome product of two 3-digit numbers: " << max_palindrome << endl;
    return 0;
}