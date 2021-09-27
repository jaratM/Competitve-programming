// problem set: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-round-numbers/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) + 1)
#define M(X, Y) ((X + Y) >> 1)
const int MAX = 2 * 1e5 + 5;
int pre[MAX], seg[MAX * 4];
int n, q;
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = pre[l];
    }
    else
    {
        int m = M(l, r);
        build(L(id), l, m);
        build(R(id), m + 1, r);
        seg[id] = seg[L(id)] + seg[R(id)];
    }
}
void update(int i, int v, int id, int l, int r)
{
    if (l == r)
    {
        seg[id] += v;
        pre[i] += v;
    }
    else
    {
        int m = M(l, r);
        if (i <= m)
            update(i, v, L(id), l, m);
        else
            update(i, v, R(id), m + 1, r);
        seg[id] = seg[L(id)] + seg[R(id)];
    }
}
int get(int x, int y, int id, int l, int r)
{
    if (x > r || y < l)
        return 0;
    if (x <= l && r <= y)
        return seg[id];
    int m = M(l, r);
    return get(x, y, L(id), l, m) + get(x, y, R(id), m + 1, r);
}
int check(Long x)
{
    int l = (x % 10);
    while (x >= 10)
    {
        x /= 10;
    }
    return (x == l);
}
int main(int argc, char const *argv[])
{
    Long x;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        pre[i] = check(x);
    }
    build(1, 1, n);
    int i, l, r;
    while (q--)
    {
        scanf("%d", &i);
        if (i == 1)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", get(l, r, 1, 1, n));
        }
        else
        {
            scanf("%d%lld", &l, &x);
            int y = check(x);
            if (y && pre[l] == 0)
            {
                update(l, 1, 1, 1, n);
            }
            else if (y == 0 && pre[l])
                update(l, -1, 1, 1, n);
        }
    }
    return 0;
}
