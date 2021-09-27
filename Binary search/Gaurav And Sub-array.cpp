// problem: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/gaurav-and-subarray-3-787fb90a/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int binary(int x)
{
    int s = 0;
    while (x != 0)
    {
        if (x % 2 == 1)
            s++;
        x /= 2;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    int n, q, k, x;

    scanf("%d %d", &n, &q);
    std::vector<int> T(n + 1);
    T[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        T[i] = binary(x) + T[i - 1];
    }
    while (q--)
    {
        cin >> x;
        int low = 1, high = n, ans, mi = 1e6 + 1;
        while (low <= high)
        {
            ans = (low + high) / 2;
            int i = 0, j = n;
            bool boolean = false;
            while (i + ans <= n)
            {
                if (T[i + ans] - T[i] >= x)
                {
                    mi = min(mi, ans);
                    boolean = true;
                    break;
                }
                i++;
                j--;
            }
            if (boolean)
                high = ans - 1;
            else
                low = ans + 1;
        }
        if (mi != 1e6 + 1)
            printf("%d\n", mi);
        else
            printf("-1\n");
    }
}
Language : C++