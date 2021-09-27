// problem set : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/string-query-22/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 200005;
int n, q;
int pre[27][MAX];
char T[MAX];
int marque[MAX];
void update(int i, int v, int ind)
{
    while (i <= n)
    {
        pre[ind][i] += v;
        i += (i & -i);
    }
}
int get(int i, int index)
{
    int sum = 0;
    while (i > 0)
    {
        sum += pre[index][i];
        i -= (i & -i);
    }
    return sum;
}

int findKthSmallest(int k, int index)
{
    int l = 1;
    int h = n;
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= get(mid, index))
            h = mid;
        else
            l = mid + 1;
    }

    return l;
}
int main(int argc, char const *argv[])
{
    int x;
    int index;
    scanf("%s", T + 1);
    n = strlen(T + 1);
    for (int i = 1; T[i]; i++)
    {
        index = T[i] - 'a',
        update(i, 1, index);
    }
    scanf("%d", &q);
    char C;
    while (q--)
    {

        cin >> x >> C;
        index = C - 'a';
        int ans = findKthSmallest(x, index);
        marque[ans] = 1;
        update(ans, -1, index);
    }
    for (int i = 1; T[i]; i++)
    {
        if (marque[i] == 0)
            cout << T[i];
    }
    return 0;
}
