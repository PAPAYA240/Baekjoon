#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define INF 2e9

int n, m, k, x; // 도시 개수, 도로 개수, 거리 정보, 출발 도시 번호
vector<pair<int, int>> v[1000001];
int dist[1000001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
    
	while (!pq.empty())
	{
		int node1 = pq.top().first;
		int node2 = pq.top().second;
		pq.pop();

		// 이미 최단 경로 체크함
		if (dist[node2] < node1)
			continue;

		// 중간 경로 탐색
		for (int i = 0; i < v[node2].size(); i++)
		{
            int next_node = v[node2][i].first; 
            int weight = v[node2][i].second;  

            int cost = node1 + weight; 

            if (cost < dist[next_node])
            {
                dist[next_node] = cost; 
                pq.push({ cost, next_node });
            }
		}
	}
}

int main()
{
	cin >> n >> m >> k >> x;
	int a, b;
    fill_n(dist + 1, 1000001, INF);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].emplace_back(make_pair( b, 1 ));
	}

	dijkstra(x);

	int result = -1;
	for (int i = 1; i <= n; i++)
	{
		if (k == dist[i])
		{
			cout << i << "\n";
			result = i;
		}
	}
	if (-1 == result)
		cout << -1;
}