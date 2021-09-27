// Problem set: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/once-upon-a-time-in-time-land/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 1e4 + 6;
int T[MAX], n, k, t;
Long M[MAX];
Long solve(int i)
{
    if (i > n)
        return 0;
    if (M[i] != -1)
        return M[i];
    return M[i] = max(solve(i + k + 1) + T[i], solve(i + 1));
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", T + i);
        }
        memset(M, -1, sizeof(M));
        printf("%lld\n", solve(1));
    }
    return 0;
}