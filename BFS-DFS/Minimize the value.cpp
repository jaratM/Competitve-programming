// problem set: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimize-the-magic-05a3986c/
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 6;
std::vector<int> v[MAX];
long long int T[MAX];
int M[MAX], level[MAX];
void dfs(int x)
{
	M[x] = 1;
	for (int i = 0; i < v[x].size(); ++i)
	{
		if (M[v[x][i]] == 0)
		{
			level[v[x][i]] = level[x] + 1;
			dfs(v[x][i]);
		}
	}
}

void dfs1(int x)
{
	M[x] = 1;
	for (int i = 0; i < v[x].size(); ++i)
	{
		if (M[v[x][i]] == 0)
		{
			dfs1(v[x][i]);
			T[x] += T[v[x][i]];
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", T + i);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (v[1].size() == 1)
	{
		v[n + 1].push_back(1);
		v[1].push_back(n + 1);
	}
	else
	{
		level[1] = 0;
		dfs(1);
		int ans = 10000000, ind = 0;
		for (int i = 2; i < n + 1; ++i)
		{
			if (level[i] < ans && v[i].size() <= 2)
			{
				ans = level[i];
				ind = i;
			}
		}
		v[ind].push_back(n + 1);
		v[n + 1].push_back(ind);
		memset(M, 0, sizeof(M));
	}
	T[n + 1] = m;
	dfs1(1);
	long long int ans = 0;
	for (int i = 1; i < n + 2; ++i)
	{
		ans += T[i];
	}
	printf("%lld\n", ans);
}
