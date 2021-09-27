// problem : https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/highest-average-64bdd761/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAX = 5 * 1e5 + 5;
ll T[MAX];
int n, q, x;
void check()
{
	int low = 1, high = n, ans = 0;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		int div = (int)(T[mid] / mid);
		if (div < x)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", T + i);
	}
	sort(T, T + n + 1);
	scanf("%d", &q);
	for (int i = 1; i <= n; i++)
	{
		T[i] += T[i - 1];
	}
	while (q--)
	{
		scanf("%d", &x);
		check();
	}
}
