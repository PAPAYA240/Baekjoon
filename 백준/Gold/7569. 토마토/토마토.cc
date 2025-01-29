#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;

queue<tuple<int, int, int>> que;
int map[101][101][101];
bool visit[101][101][101];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0 , 0, 0, 1, -1 };

// DFS + 재귀 함수
//void DFS(int _x, int _y, int _z)
//{
//	for (int i = 0; i < 6; i++)
//	{
//		int nx = _x + dx[i];
//		int ny = _y + dy[i];
//		int nz = _z + dz[i];
//
//		if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= K)
//			continue;
//
//		if (visit[nx][ny][nz] || map[nx][ny][nz] != 0)
//			continue;
//
//		visit[nx][ny][nz] = true;
//		map[nx][ny][nz] = map[_x][_y][_z] + 1;
//		DFS(nx, ny, nz);
//	}
//}

int BFS()
{
	while(!que.empty())
	{
		tuple<int, int, int> value = que.front();
		que.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = get<0>(value) + dx[i];
			int ny = get<1>(value) + dy[i];
			int nz = get<2>(value) + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= K)
				continue;

			if (visit[nx][ny][nz] || map[nx][ny][nz] != 0)
				continue;

			visit[nx][ny][nz] = true;
			map[nx][ny][nz] = map[get<0>(value)][get<1>(value)][get<2>(value)] + 1;
			que.push({ nx, ny, nz });
		}
	}

	int days = 0;
	for (int z = 0; z < K; z++)
	{
		for (int y = 0; y < M; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (days < map[x][y][z])
					days = map[x][y][z];

				if (0 == map[x][y][z])
					return -1;
			}
		}
	}
	return days - 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;
	for (int z = 0; z < K; z++)
	{
		for (int y = 0; y < M; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> map[x][y][z];

				if (1 == map[x][y][z])
					que.push({ x, y, z });
			}
		}
	}

	cout << BFS();
}