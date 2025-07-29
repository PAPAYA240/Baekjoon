#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9

using namespace std;

vector<pair<int, int>> v[300001];
int dist[20001];

void Dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int currentDist = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (dist[currentNode] < currentDist)
			continue;

		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode][i].first;
			int nextDist = v[currentNode][i].second;
			int cost = nextDist + currentDist;

			if (cost >= dist[nextNode])
				continue;

			dist[nextNode] = cost;
			pq.push({ cost, nextNode });
		}
	}
}

int main()
{
	int V, e, k;
	cin >> V >> e >> k;
	fill_n(dist, V + 1, INF);

	int u, a, w;
	for (int i = 0; i < e; i++)
	{
		cin >> u >> a >> w;
		v[u].emplace_back(make_pair(a, w));
	}
	Dijkstra(k);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}
}