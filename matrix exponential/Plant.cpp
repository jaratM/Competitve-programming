// problem set : https://codeforces.com/contest/185/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;
typedef long double Double;
const int mod = 1e9 + 7;
struct Mat
{
	Long T[2][2];
	Mat()
	{
		T[0][0] = T[1][1] = 3;
		T[0][1] = T[1][0] = 1;
	}
	Mat operator*(const Mat &a) const
	{
		Mat rep;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				Long &sum = rep.T[i][j] = 0;
				for (int k = 0; k < 2; k++)
				{
					sum = (sum + T[i][k] * 1LL * a.T[k][j]) % mod;
				}
			}
		}
		return rep;
	}
};

Mat bp(Mat a, Long n)
{
	if (n == 1)
		return a;
	Mat rep = bp(a, n / 2);
	rep = rep * rep;
	return (n % 2 == 0) ? rep : rep * a;
}
int main(int argc, char const *argv[])
{
	Long n;
	cin >> n;
	if (n == 0)
		return 0 * printf("1\n");
	Mat rep;
	rep = bp(rep, n);
	Long ans = (rep.T[0][0]);
	cout << ans;
}