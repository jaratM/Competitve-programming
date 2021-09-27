https : //www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/help-the-avengers-6/
#include <bits/stdc++.h>
        using namespace std;
typedef long long int Long;
typedef long double Double;
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) + 1)
#define M(X, Y) ((X + Y) >> 1)
const int MAX = 1e6 + 1;
int prime[MAX], seg[32000 * 4], T[32001];
void sieve()
{
    prime[1] = 1;
    for (Long i = 2; i < MAX; i++)
    {
        if (prime[i] == 0)
        {
            for (Long j = i * i; j < MAX; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = T[l];
    }
    else
    {
        int m = M(l, r);
        build(L(id), l, m);
        build(R(id), m + 1, r);
        seg[id] = seg[R(id)] + seg[L(id)];
    }
}
int get(int x, int y, int id, int l, int r)
{
    if (x > r || y < l)
        return 0;
    if (x <= l && r <= y)
        return seg[id];
    int m = M(l, r);
    return (get(x, y, L(id), l, m) + get(x, y, R(id), m + 1, r));
}
void update(int i, int v, int id, int l, int r)
{
    if (l == r)
    {
        seg[id] += v;
        T[i] += v;
    }
    else
    {
        int m = M(l, r);
        if (i <= m)
        {
            update(i, v, L(id), l, m);
        }
        else
            update(i, v, R(id), m + 1, r);
        seg[id] = seg[R(id)] + seg[L(id)];
    }
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    sieve();
    while (t--)
    {
        memset(seg, 0, sizeof(seg));
        memset(T, 0, sizeof(T));
        int n, q;
        scanf("%d", &n);
        int x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            if (prime[x] == 0)
            {
                T[i] = 1;
            }
        }
        build(1, 1, n);
        scanf("%d", &q);
        string str;
        int l, r;
        while (q--)
        {
            cin >> str;
            scanf("%d%d", &l, &r);
            if (str == "A")
            {
                printf("%d\n", get(l, r, 1, 1, n));
            }
            else
            {
                if (T[l] == 1 && prime[r] == 1)
                    update(l, -1, 1, 1, n);
                else if (T[l] == 0 && prime[r] == 0)
                    update(l, 1, 1, 1, n);
            }
        }
    }

    return 0;
}
