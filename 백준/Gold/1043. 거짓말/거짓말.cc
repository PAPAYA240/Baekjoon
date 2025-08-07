#include<iostream>
#include<vector>

using namespace std;

int n, m, k;
vector<bool> truth;
vector<vector<int>> partymember;
vector<vector<int>> map;

void Relation(vector<int> rel)
{
	for (auto iter : rel)
	{
		map[rel[0]][iter] = 1;
		map[iter][rel[0]] = 1;
	}
}

void DFS(int me)
{
	for (int j = 1; j <= n; j++)
	{
		// 이미 진실을 아는 자라면
		if (truth[j])
			continue;

		// 진실을 알릴 수 없는 자라면
		if (map[me][j] != 1)
			continue;

		// 알지 못하지만 관계를 맺는 자라면
		truth[j] = 1;
		DFS(j);
	}
}

int main()
{
	cin >> n >> m >> k;
	truth.resize(n + 1);
	partymember.resize(m);
	map.resize(n + 1, vector<int>(n + 1));

	// 진실을 아는 사람
	for (int i = 0; i < k; i++)
	{
		int val;
		cin >> val;
		truth[val] = true;
	}

	// 파티 모임
	for (int i = 0; i < m; i++)
	{
		int val;
		cin >> val;
		for(int j = 0; j < val; j++)
		{
			int num;
			cin >> num;
			partymember[i].emplace_back(num);
		}
		Relation(partymember[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (false == truth[i])
			continue;
		DFS(i);
	}

	int lieparty = 0;
	for(int i = 0; i < m; i++)
	{
		// 알 지 못하는 파티라면
		if (!truth[partymember[i][0]])
			++lieparty;
	}
	cout << lieparty;
}