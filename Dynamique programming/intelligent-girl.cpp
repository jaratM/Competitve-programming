// problem set: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/intelligent-girl-1/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e4 + 5;
const int mod = 1e9 + 7;
char fact[MAXN];
int T[MAXN], n = 1, even;
void solve()
{
    for (int i = 1; fact[i]; i++)
    {
        if ((fact[i] - '0') % 2 == 0)
        {
            ++even;
            T[i] = 1;
        }
        n++;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", fact + 1);
    solve();
    for (int i = 1; i < n; i++)
    {
        if (T[i] == 1)
        {
            printf("%d ", even);
            even--;
        }
        else
            printf("%d ", even);
    }
    return 0;
}
