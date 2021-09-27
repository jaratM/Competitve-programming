// problem: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/compare-strings-1-1cb66e03/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
	int n, q, x;
	scanf("%d %d", &n, &q);
	set<int> v;
	string A, B;
	cin >> A >> B;
	for (int i = 0; i < n; i++)
	{
		if (A[i] != B[i])
			v.insert(i);
	}
	while (q--)
	{
		scanf("%d", &x);
		;
		x--;
		B[x] = '1';
		if (B[x] != A[x])
			v.insert(x);
		else if (v.find(x) != v.end())
			v.erase(x);
		if (v.size() != 0)
		{
			if (A[*v.begin()] < B[*v.begin()])
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("YES\n");
	}
}
