// problem set: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/buy-and-sell/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAX = 1e5 + 5;
int pre[MAX], val[MAX], cnt[MAX];
map<string, int> m;
int n, q;
void update(int i, int v)
{
    while (i <= 100000)
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
    return get(r) - get(l);
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    char str[15];
    int x, p;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d", str, &x);
        m[str] = i;
        val[i] = x;
    }
    scanf("%d", &q);
    //char C;
    while (q--)
    {
        scanf("%s", str);
        if (str[0] == '?')
        {
            scanf("%d", &x);
            printf("%d\n", get(x, 100000));
        }
        else if (str[0] == '-')
        {
            scanf("%s", str);
            p = m[str];
            if (cnt[p])
            {
                cnt[p]--;
                update(val[p], -1);
            }
        }
        else
        {
            scanf("%s", str);
            p = m[str];
            update(val[p], 1);
            cnt[p]++;
        }
    }
    return 0;
}
