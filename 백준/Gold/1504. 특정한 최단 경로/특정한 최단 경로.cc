#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define INF 1e9

using namespace std;

int n, m, l, k;
vector<pair<int, int>> v[200001];
int cost[801];

void Dijkstra(int _start)
{
	fill_n(cost, n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, _start });
	cost[_start] = 0;

	while (!pq.empty())
	{
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (cost[currentNode] < currentCost)
			continue;

		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode][i].first;
			int nextCost = currentCost + v[currentNode][i].second;

			if (nextCost >= cost[nextNode])
				continue;

			cost[nextNode] = nextCost;
			pq.push({ nextCost, nextNode });
		}
	}

}

int main()
{
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].emplace_back(make_pair(b, c));
		v[b].emplace_back(make_pair(a, c));
	}
	cin >> k >> l;

	Dijkstra(1);
	int toA = cost[k];
	int toB = cost[l];

	// A
	Dijkstra(k);
	int A_to_B = cost[l];
	int A_to_N = cost[n];

	// B
	Dijkstra(l);
	int B_to_N = cost[n];

	long long resultA = (long long)toA + (long long)A_to_B + (long long)B_to_N;
	long long resultB = (long long)toB + (long long)A_to_B + (long long)A_to_N;
	long long result = min(resultA ,resultB);
	(result >= INF) ? cout << "-1" : cout << result;
}