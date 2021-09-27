// problem set: https://www.hackerearth.com/practice/math/number-theory/totient-function/practice-problems/algorithm/nanachi-and-euler-totient-4-1f3f29ca/
#include <bits/stdc++.h>
using namespace std;
#define Long long long int
const int MAXN = 1e6 + 5;
const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;
map<Long, Long> m;
vector<Long> v;
Long N;

void Divisors(Long n)
{
    for (Long i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            if (n / i != i)
                v.push_back(n / i);
            v.push_back(i);
        }
}

void primeFactors(Long n)
{
    for (Long i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        m[n]++;
    }
}

Long bp(Long m, Long p)
{
    if (p == 1)
        return m;
    Long tmp = bp(m, p / 2);
    tmp = (tmp % MOD * tmp % MOD) % MOD;
    return (p % 2 == 0) ? tmp : (tmp % MOD * m % MOD) % MOD;
}

int main(int argc, char const *argv[])
{
    scanf("%lld", &N);
    Divisors(N);
    Long res = 1, expe;
    for (Long i : v)
    {
        m.clear();
        primeFactors(i);
        for (auto &e : m)
        {
            expe = bp(e.first, e.second);
            res *= (expe % MOD - (expe / e.first) % MOD + MOD) % MOD;
            res %= MOD;
        }
    }
    printf("%lld\n", res);
    return 0;
}
