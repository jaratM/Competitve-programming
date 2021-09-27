// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/fibonacci-with-gcd-16/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
#define L(ID) (ID << 1)
#define R(ID) ((ID << 1) + 1)
#define M(X, Y) ((X + Y) >> 1)
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int T[MAX], seg[MAX * 4];
int n, q;
struct mat
{
    int a[2][2];
    mat()
    {
        a[0][0] = a[0][1] = a[1][0] = 1;
        a[1][1] = 0;
    }
    mat operator*(const mat &m) const
    {
        mat ret;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
            {
                int &sum = ret.a[i][j] = 0;
                for (int k = 0; k < 2; ++k)
                {
                    sum = (sum + a[i][k] * 1LL * m.a[k][j]) % MOD;
                }
            }
        return ret;
    }
};
mat bp(mat m, int p)
{
    if (p == 1)
        return m;
    mat tmp = bp(m, p / 2);
    tmp = (tmp * tmp);
    return (p % 2 == 0) ? tmp : (tmp * m);
}

int gcd(int a, int b)
{
    if (!a || !b)
        return a + b;
    else
        return __gcd(a, b);
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
        seg[id] = gcd(seg[L(id)], seg[R(id)]);
    }
}

int get(int x, int y, int id, int l, int r)
{
    if (x > r || y < l)
        return 0;
    if (x <= l && r <= y)
        return seg[id];
    int m = M(l, r);
    return gcd(get(x, y, L(id), l, m), get(x, y, R(id), m + 1, r));
}
int main(int argc, char const *argv[])
{

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", T + i);
    build(1, 1, n);
    int l, r;
    while (q--)
    {
        scanf("%d%d", &l, &r);
        int ans = get(l, r, 1, 1, n);
        mat m;
        if (ans > 1)
            m = bp(m, ans - 1);
        ans = m.a[0][0];
        printf("%d\n", ans);
    }

    return 0;
}
Language : C++
