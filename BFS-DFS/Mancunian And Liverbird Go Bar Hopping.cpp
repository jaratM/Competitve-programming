// problem set: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/mancunian-and-liverbird-go-bar-hopping-2/
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 6;
int T0[MAX], ans1[MAX], U[MAX];
int main(int argc, char const *argv[])
{
	int n, q, x;
	char c[2];
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &x);
		T0[i] = x;
	}

	for (int i = 1; i < n; i++)
	{
		if (T0[i] == 0)
		{
			ans1[i + 1] += ans1[i] + 1;
		}
		else
		{
			U[i + 1] += U[i] + 1;
		}
	}

	for (int i = n; i > 0; i--)
	{
		if (T0[i - 1])
		{
			ans1[i - 1] += ans1[i] + 1;
		}
		else
		{
			U[i - 1] += U[i] + 1;
		}
	}

	scanf("%d", &q);
	bool up = false;

	while (q--)
	{
		scanf("%s", c);
		if (c[0] == 'Q')
		{
			scanf("%d", &x);
			if (up)
				printf("%d\n", U[x] + 1);
			else
				printf("%d\n", ans1[x] + 1);
		}
		else
			up = !up;
	}
}
Language : C++