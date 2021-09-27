// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-confused-monk/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int T[1001], n;
int MOD = 1e9 + 7;
int mi = 1e3;
ll power(ll x, int m)
{
    if (m == 0)
        return 1;
    ll res = power(x, m / 2);
    res = (res * res) % MOD;
    return (m % 2 == 0) ? res : (res * x) % MOD;
}
ll solve(ll mul)
{
    int ans = 1;
    for (int i = 2; i <= mi; i++)
    {
        bool tst = true;
        for (int j = 0; j < n; j++)
        {
            if (T[j] % i != 0)
            {
                tst = false;
                break;
            }
        }
        if (tst)
            ans = i;
    }
    return power(mul, ans);
}
int main(int argc, char const *argv[])
{

    int x;
    scanf("%d", &n);
    ll mul = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", T + i);
        mul = (mul * T[i]) % MOD;
        mi = min(T[i], mi);
    }
    printf("%d\n", solve(mul));
}
