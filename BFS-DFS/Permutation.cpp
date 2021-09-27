// problem set: https://www.hackerearth.com/problem/algorithm/t1-1-6064aa64/
#include <bits/stdc++.h>
using namespace std;

int n, a[10];
vector<int> start;
map<vector<int>, int> dist;
queue<vector<int>> Q;

bool isSorted(vector<int> &p)
{
    for (int i = 1; i < n; ++i)
    {
        if (a[p[i]] < a[p[i - 1]])
        {
            return false;
        }
    }
    return true;
}

vector<vector<int>> nextPerm(vector<int> &base)
{
    vector<vector<int>> perms;
    for (int i = 1; i < n; ++i)
    {
        vector<int> p;
        for (int j = i; j >= 0; --j)
            p.push_back(base[j]);
        for (int j = i + 1; j < n; ++j)
            p.push_back(base[j]);
        perms.push_back(p);
    }
    return perms;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        start.push_back(i);
    }

    dist[start] = 1;
    Q.push(start);
    while (Q.size())
    {
        vector<int> p = Q.front();
        Q.pop();
        int pdist = dist[p];

        if (isSorted(p))
        {
            return 0 * printf("%d\n", pdist - 1);
        }

        for (vector<int> op : nextPerm(p))
        {
            int &opdist = dist[op];
            if (opdist == 0)
            { // not visited
                opdist = pdist + 1;
                Q.push(op);
            }
        }
    }

    return 0;
}
