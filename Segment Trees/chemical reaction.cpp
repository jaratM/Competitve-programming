// problem set: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/chemical-reaction/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 500005;
int n, q;
int pre[MAX];
std::vector<pair<string, int>> v(MAX);
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

int findKthSmallest(int k)
{
    int l = 1;
    int h = n;
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= get(mid))
            h = mid;
        else
            l = mid + 1;
    }

    return l;
}
int main(int argc, char const *argv[])
{
    int t, x;
    string str;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            v[i].first = str;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            update(i, 1);
            v[i].second = x;
        }
        q = n - 1;
        int val = -1;
        while (q--)
        {
            scanf("%d", &x);
            int ans = findKthSmallest(x);
            val = max(val, v[ans].second);
            cout << v[ans].first;
            printf(" %d\n", val);
            update(ans, -1);
        }
        int ans = findKthSmallest(1);
        val = max(val, v[ans].second);
        cout << v[ans].first;
        printf(" %d\n", val);
        v.clear();
        memset(pre, 0, sizeof(pre));
    }

    return 0;
}
Language : C++ c