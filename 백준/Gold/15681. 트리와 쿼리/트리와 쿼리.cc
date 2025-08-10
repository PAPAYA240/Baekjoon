#include<iostream>
#include<vector>

using namespace std;

int N, R, Q;
vector<vector<int>> v;
vector<bool> visited;
vector<int> cost;

int DFS(int currentNode)
{
	visited[currentNode] = true;
	for (const auto& iter : v[currentNode])
	{
		if (visited[iter])
			continue;
		int result = DFS(iter);
		cost[currentNode] += result;
	}
	return cost[currentNode];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> N >> R >> Q;
	v.resize(N + 1);
	visited.resize(N + 1, false);
	cost.resize(N + 1, 1);

	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}

	DFS(R);
	int input;
	for (int i = 0; i < Q; i++)
	{
		cin >> input;
		cout << cost[input] << '\n';
	}
}