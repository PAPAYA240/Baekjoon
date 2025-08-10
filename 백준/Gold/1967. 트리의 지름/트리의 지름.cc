#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 1. 플로이드 워셜 : 음수가 존재하는 가중치에는 유용하지만, 사이클이 존재하지 않는 트리에 유용하지 않는다,
// 2. 가중치를 찾는 문제더라도 깊이 탐색을 통해서 지름을 먼저 찾는 것이 좋다.

int n;
vector<vector<pair<int, int>>> v;
vector<vector<int>> costArr;

int DFS(int currentIdx, int prevIdx, int myidx)
{
	int maxres = 0;
	for (const auto& iter : v[currentIdx])
	{
		int nextIdx = iter.first;
		int weight = iter.second;
		int res = DFS(nextIdx, currentIdx, myidx) + weight;
		maxres = max(maxres, res);
		if (myidx == currentIdx)
			costArr[myidx].emplace_back(res);
	}
	return maxres;
}
int main()
{
	cin >> n;
	int a, b, c;
	v.resize(n + 1);
	costArr.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		v[a].emplace_back(make_pair(b, c));
	}

	for(int i = 1; i <=n; i++)
		DFS(i, i, i);

	for (int i = 1; i <= n; i++)
		sort(costArr[i].begin(), costArr[i].end());

	vector<int> resultCost(n + 1, 0);
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if (costArr[i].empty())
				continue;
			resultCost[i] += costArr[i].back();
			costArr[i].pop_back();
		}
		result = max(result, resultCost[i]);
	}
	cout << result;
}