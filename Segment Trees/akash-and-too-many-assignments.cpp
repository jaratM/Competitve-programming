// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-too-many-assignments/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 1e6 + 5;
int pre[26][MAX];
char T[MAX], s[2];
int n, q, k;
int ans[27], ans1[27];
void update(int k, char C, int v)
{
    int l = k;
    while (k <= n)
    {
        pre[C - 'a'][k] += v;
        k += (k & -k);
    }
}
void get(int i)
{
    while (i > 0)
    {
        for (int j = 0; j < 26; j++)
        {
            ans[j] += pre[j][i];
        }
        i -= (i & -i);
    }
}
void get2(int i)
{
    while (i > 0)
    {
        for (int j = 0; j < 26; j++)
        {
            ans1[j] += pre[j][i];
        }
        i -= (i & -i);
    }
}
void get1(int l, int r)
{
    get(r);
    get2(l - 1);
    for (int i = 0; i < 26; i++)
    {
        if (k > ans[i] - ans1[i])
            k -= (ans[i] - ans1[i]);
        else
        {
            printf("%c\n", i + 'a');
            return;
        }
    }
    printf("Out of range\n");
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%s", &n, &q, T + 1);
    for (int i = 1; i <= n; i++)
    {
        update(i, T[i], 1);
    }
    int i, x, y;
    while (q--)
    {
        scanf("%d", &i);
        if (i == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            if (y - x + 1 >= k)
            {
                memset(ans, 0, sizeof(ans));
                memset(ans1, 0, sizeof(ans1));
                get1(x, y);
            }
            else
                printf("Out of range\n");
        }
        else
        {
            scanf("%d %s", &k, s);
            if (T[k] != s[0])
            {
                update(k, s[0], 1);
                update(k, T[k], -1);
                T[k] = s[0];
            }
        }
    }
    return 0;
}
