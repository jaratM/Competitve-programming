// problem set: https://codeforces.com/problemset/problem/166/E
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int mod = 1000000007;
const int MAX = 1e9 + 5;
struct mat
{
	vector<Long> a[4];
	mat()
	{
		a[0] = {0, 1, 1, 1};
		a[1] = {1, 0, 1, 1};
		a[2] = {1, 1, 0, 1};
		a[3] = {1, 1, 1, 0};
	}
	mat operator*(const mat &m) const
	{
		mat ret;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Long &sum = ret.a[i][j] = 0;
				for (int k = 0; k < 4; k++)
				{
					sum = (sum + a[i][k] * 1LL * m.a[k][j]) % mod;
				}
			}
		}
		return ret;
	}
};
mat bp(mat b, int n)
{
	if (n == 1)
		return b;
	mat rep = bp(b, n / 2);
	rep = rep * rep;
	return (n % 2 == 0) ? rep : rep * b;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	if (n == 1)
		printf("0\n");
	else
	{
		mat ans;
		ans = bp(ans, n - 1);
		int rep = (ans.a[0][2] + ans.a[0][1] + ans.a[0][3]) % mod;
		printf("%d\n", rep);
	}
	return 0;
}