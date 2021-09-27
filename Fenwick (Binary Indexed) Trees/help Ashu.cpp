// problem set: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 1e5 + 5;
int n, q;
int pre[MAX], T[MAX];
void update(int i, int v)
{
    while (i <= n)
    {
        pre[i] += v;
        i += (i & -i);
    }
}
int get(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += pre[i];
        i -= (i & -i);
    }
    return sum;
}
int get(int l, int r)
{
    return get(r) - get(l - 1);
}
int main(int argc, char const *argv[])
{
    int x, l, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", T + i);
        if (T[i] % 2 == 0)
            update(i, 1);
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d", &x, &l, &r);
        if (x == 1 || x == 2)
        {
            int ans = get(l, r);
            (x == 1) ? printf("%d\n", ans) : printf("%d\n", r - l + 1 - ans);
        }
        else
        {
            if (T[l] % 2 == 0 && r % 2 != 0)
                update(l, -1);
            else if (T[l] % 2 != 0 && r % 2 == 0)
                update(l, 1);
            T[l] = r;
        }
    }
    return 0;
}
