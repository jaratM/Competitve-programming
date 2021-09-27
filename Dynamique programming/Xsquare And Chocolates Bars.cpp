// problem set: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-chocolates-bars-2/
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int MAX = 1e6 + 6;
char T[MAX];
int n, k, t, M[MAX], ans[MAX];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", T + 1);
        n = strlen(T + 1);
        memset(M, 0, sizeof(M));
        for (int i = 1; i <= n; i++)
        {
            if (T[i] == 'S')
                M[i] = 1;
            M[i] += M[i - 1];
            ans[i] = 0;
            //printf("%d\n",M[i]);
        }
        int len = 0;

        for (int i = 3; i <= n; i++)
        {
            if ((M[i] - M[i - 3]) % 3 != 0)
                ans[i] += ans[i - 3] + 1;
            //	printf("%d %d >= %d\n",ans[i] ,M[i],M[i-3]);
            //printf("%d\n",ans[i]);
            len = max(len, ans[i]);
        }
        printf("%d\n", n - (len * 3));
    }
    return 0;
}
Language : C++
