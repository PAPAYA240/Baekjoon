#include<iostream>
#include<queue>
#include<vector>
#include<limits>

using namespace std;

const int INF = numeric_limits<int>::max();
vector<long long> dist;
vector<pair<int, int>> v[50001];

void Dijkstra(int start)
{
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int currentNode = pq.top().first;
		int currentDist = pq.top().second;
		pq.pop();

		if (dist[currentNode] < currentDist)
			continue;

		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode][i].first;
			int nextDist = v[currentNode][i].second;
			long long cost = (long long)(currentDist + nextDist);

			if (cost >= dist[nextNode])
				continue;

			dist[nextNode] = cost;
			pq.push({ nextNode, cost });
		}
	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	dist.resize(50001, INF);

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].emplace_back(make_pair(b, c));
		v[b].emplace_back(make_pair(a, c));
	}

	Dijkstra(1);

	cout << dist[n];
}