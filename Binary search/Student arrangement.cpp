// problem: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/student-arrangement-6/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int T[MAX];
int n, m, k, x;

int main(int argc, char const *argv[])
{
    int count = 0;
    scanf("%d%d%d", &n, &m, &k);
    set<int> free;
    set<int>::iterator it;
    for (int i = 1; i <= m; ++i)
    {
        free.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (T[x] < k)
        {
            T[x]++;
            if (T[x] == k)
                free.erase(x);
        }
        else
        {
            count++;
            if (!free.empty())
            {
                it = free.upper_bound(x);
                if (it == free.end())
                {
                    it = free.begin();
                }
                T[*it]++;
                if (T[*it] == k)
                    free.erase(it);
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

