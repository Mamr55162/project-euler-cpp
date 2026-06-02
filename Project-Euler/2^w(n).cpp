#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000087LL;

long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse
long long modinv(long long a, long long mod)
{
    return power(a, mod - 2, mod);
}

int main()
{
    const int N = 10000000;

    // Sieve of smallest prime factor
    vector<int> spf(N + 1, 0); // smallest prime factor
    for (int i = 2; i <= N; i++)
        if (spf[i] == 0)
            for (int j = i; j <= N; j += i)
                if (spf[j] == 0)
                    spf[j] = i;

    // Collect primes in order
    vector<int> primes;
    for (int i = 2; i <= N; i++)
        if (spf[i] == i)
            primes.push_back(i);

    // v[p] = current exponent of prime p in factorial
    // We keep track of (1 + 2*v[p]) mod MOD for each prime
    // S(i!) = product of (1 + 2*v_p(i!)) for all primes p <= i
    // We maintain S_val = S(i!) mod MOD

    // Use a vector indexed by prime index
    int numPrimes = (int)primes.size();
    vector<long long> coeff(numPrimes, 1LL); // (1 + 2*v_p) for prime index k
    vector<long long> vp(numPrimes, 0LL);    // exponent of primes[k] in current factorial

    long long S_val = 1; // S(0!) = S(1!) = 1 (empty product or product over no primes)
    long long F_val = 0;

    // Prime index lookup (we'll iterate primes in sorted order up to i)
    // For efficiency, maintain a running index of the largest prime <= current i
    int primePtr = 0; // index into primes[] of first prime > current i

    for (int i = 2; i <= N; i++)
    {
        // Update vp for all primes p <= i
        // The exponent of p in i! increases by floor(i/p) + floor(i/p^2) + ...
        // compared to (i-1)!. Actually the INCREMENTAL increase going from (i-1)! to i!
        // equals v_p(i) = exponent of p in i itself.
        // So just factorize i:
        int tmp = i;
        // Update new prime if i is prime
        if (spf[i] == i)
        {
            // i is prime, add it
            // primes[primePtr] == i at this point
            // vp[primePtr] was 0, now becomes 1
            vp[primePtr] = 1;
            long long oldCoeff = 1LL; // (1 + 2*0)
            long long newCoeff = 3LL; // (1 + 2*1)
            coeff[primePtr] = newCoeff;
            S_val = S_val % MOD * modinv(oldCoeff, MOD) % MOD * newCoeff % MOD;
            primePtr++;
            tmp = 1;
        }
        else
        {
            // Composite: factorize using spf
            while (tmp > 1)
            {
                int p = spf[tmp];
                // Find index of p in primes[]
                // Binary search
                int lo = 0, hi = primePtr - 1, idx = -1;
                while (lo <= hi)
                {
                    int mid = (lo + hi) / 2;
                    if (primes[mid] == p) { idx = mid; break; }
                    else if (primes[mid] < p) lo = mid + 1;
                    else hi = mid - 1;
                }
                // Count exponent of p in i
                long long inc = 0;
                while (tmp % p == 0) { tmp /= p; inc++; }
                long long oldCoeff = coeff[idx];
                vp[idx] += inc;
                long long newCoeff = (1 + 2 * vp[idx]) % MOD;
                coeff[idx] = newCoeff;
                S_val = S_val % MOD * modinv(oldCoeff, MOD) % MOD * newCoeff % MOD;
            }
        }

        F_val = (F_val + S_val) % MOD;
    }

    cout << F_val << "\n";
    return 0;
}
