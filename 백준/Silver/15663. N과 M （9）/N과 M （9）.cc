#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n, m;
vector<int> v;
vector<int> store;
vector<bool> visited;
set<vector<int>> result;

void DFS(int currentIdx, int Idx)
{
	// 자릿수가 같다면
	if (Idx >= m)
	{
		result.insert(store);
		return;
	}

	// 더 채워야 한다면
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		store[Idx] = v[i];
		DFS(i, Idx + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	v.resize(n);
	store.resize(m);
	visited.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	DFS(0, 0);

	for (const auto& iter : result)
	{
		for (int i = 0; i < iter.size(); ++i)
		{
			cout << iter[i] << (i == iter.size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
}