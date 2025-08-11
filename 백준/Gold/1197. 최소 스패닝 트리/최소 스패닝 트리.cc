#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

vector<int> p;
int v, e;
tuple<int, int, int> edge[500001];

int Find(int x)
{
	if (p[x] < 0)
		return x;
	return p[x] = Find(p[x]);
}

bool Union(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v) // 같은 그룹이라면
		return false;

	if (p[v] < p[u])
		swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true; // 다른 그룹이라면
}

int main()
{
	cin >> v >> e;
	p.resize(v + 1, -1);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}

	sort(edge, edge + e);

	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		tie(c, a, b) = edge[i];

		if (!Union(a, b))
			continue;

		ans += c;
		cnt++;

		if (cnt == v - 1)
			break;
	}
	cout << ans << '\n';
}