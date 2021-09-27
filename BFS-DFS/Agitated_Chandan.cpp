// problem set: https://www.hackerearth.com/problem/algorithm/agitated-chandan/
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 6;

std::vector<pair<int, int>> v[MAX];
int dis[MAX], M[MAX];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	M[s] = 1;
	dis[s] = 0;
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (int i = 0; i < v[s].size(); ++i)
		{
			if (M[v[s][i].first] == 0)
			{
				dis[v[s][i].first] = dis[s] + v[s][i].second;
				M[v[s][i].first] = 1;
				q.push(v[s][i].first);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t, n, x, y, w;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d%d%d", &x, &y, &w);
			v[x].push_back({y, w});
			v[y].push_back({x, w});
		}
		int a = -1, b;
		bfs(1);
		for (int i = 1; i <= n; ++i)
		{
			if (dis[i] >= a)
			{
				a = dis[i];
				b = i;
			}
			dis[i] = 0;
			M[i] = 0;
		}
		bfs(b);
		a = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (dis[i] >= a)
				a = dis[i];
			v[i].clear();
			dis[i] = 0;
			M[i] = 0;
		}
		if (a < 100)
			printf("0 ");
		if (a > 100 && a < 1000)
			printf("100 ");
		if (a > 1000 && a < 10000)
			printf("1000 ");
		if (a > 10000)
			printf("10000 ");
		printf("%d\n", a);
	}
}
