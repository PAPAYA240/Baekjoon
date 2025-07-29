#include<iostream>
#include<vector>
#include<queue>

#define INF 2e9
using namespace std;

vector<pair<int, int>> v[1001];
long long dist[1001];

void dijkstra(int start)
{
	// 최소 비용 찾는 것
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		// 시작 노드에서최 단거리 노드
		int currentDist = pq.top().first;
		// 현재 노드
		int currentNode = pq.top().second; 
		pq.pop();

		// 이미 짧은 경로로 방문했다면
		if (dist[currentNode] < currentDist)
			continue;

		// 현재 노드와 연결된 이웃 노드 탐색
		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode][i].first;
			int nextDist = v[currentNode][i].second;

			// 현재 이동 비용과 다음 이동 비용
			long long cost = (long long)currentDist + nextDist;
			if (cost >= dist[nextNode])
				continue;
			// 다음 다음 노드의 비용 예측
			dist[nextNode] = cost;
			pq.push({ cost, nextNode});
		}
	}
}

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	fill_n(dist + 1, n, INF);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].emplace_back(make_pair(b, c)); // 현재 node -> next node = weigth
	}
	int start, end;
	cin >> start >> end;

	if(start)
	dijkstra(start);

	if (dist[end] == INF)
		cout << "INF";
	else
		cout << dist[end];
}