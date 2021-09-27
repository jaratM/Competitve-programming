//Problem set: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
int T[MAXN], n, q, T1[MAXN];
ll pre[MAXN], pre1[MAXN];
void solve()
{
    for (int i = 4; i <= n + 1; i += 2)
    {
        pre[i - 1] = T[i - 1] + pre[i - 3];
        pre[i] = T[i] + pre[i - 2];
    }
    //for(int i=3;i<=n+1;i++) printf("%d\n",pre[i]);
    for (int i = 4; i <= n + 1; i += 2)
    {
        pre1[i - 1] = T1[i - 1] + pre1[i - 3];
        pre1[i] = T1[i] + pre1[i - 2];
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &q);
    n += 2;
    for (int i = 3; i <= n; i++)
        scanf("%d", T + i);
    for (int i = 3; i <= n; i++)
        scanf("%d", T1 + i);
    solve();
    int l, r, k;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &k, &l, &r);
        l += 2;
        r += 2;
        ll ans = 0;
        if (k == 1)
        {
            if ((l + r) % 2 == 0)
                ans += pre[r] - pre[l - 2];
            else
                ans += pre[r - 1] - pre[l - 2];
            l++;
            if ((l + r) % 2 == 0)
                ans += pre1[r] - pre1[l - 2];
            else
                ans += pre1[r - 1] - pre1[l - 2];
        }
        else
        {
            if ((l + r) % 2 == 0)
                ans += pre1[r] - pre1[l - 2];
            else
                ans += pre1[r - 1] - pre1[l - 2];
            l++;
            if ((l + r) % 2 == 0)
                ans += pre[r] - pre[l - 2];
            else
                ans += pre[r - 1] - pre[l - 2];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
Language : C++