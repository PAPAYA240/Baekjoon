#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
tuple<int, int, int> tup[1000001];
vector<int> parent;

int Find(int x)
{
 	if (parent[x] < 0)
		return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v) // 필요 없음
		return false;

	// 루트의 높이가 더 큰 쪽을 루트로 만들어버린다.
	if (parent[v] < parent[u])
		swap(u, v);
	if (parent[u] == parent[v])
		parent[u]--;
	parent[v] = u;
	return true;
}

int main()
{
	cin >> n >> m;
	parent.resize(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tup[i] = { c, a, b };
	}
	sort(tup, tup + m);

	int cnt = 0, result = 0, last_cost = 0;
	for (int i = 0; i < m; i++)
	{
		int c, a, b;
		tie(c, a, b) = tup[i];

		if (!Union(a, b))
			continue;

		result += c;
		cnt++;
		last_cost = c;
		if (cnt == n - 1)
			break;
	}
	cout << result- last_cost;
}