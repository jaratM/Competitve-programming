// problem set : https://www.hackerearth.com/practice/math/number-theory/totient-function/practice-problems/algorithm/exam-time-2/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int mod = 1e9 + 7;
Long check(int n)
{
    Long ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ans = (ans * (i - 1)) / i;
        }
    }
    if (n > 1)
        ans = (ans * (n - 1)) / n;
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", check(n));
    }
}
