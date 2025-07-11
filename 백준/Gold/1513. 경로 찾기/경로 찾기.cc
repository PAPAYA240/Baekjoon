#include <stdio.h>

using namespace std;

int n, m, c;
int map[51][51] = {0};
int visited[51][51][51][51] = { 0 };
const int Dist = 1000007;

const int dx[2] = { 0, 1 };
const int dy[2] = { 1, 0 };

// DFS는 데이터의 개수가 조금만 커져도 시간초과가 날 확률이 높은 방법이다. 
bool IsVisited(int x, int y, int prevPosX)
{
	if (map[x][y] > prevPosX)
		return true;
	return false;
}

//void DFS(int x, int y, int cnt, int prevPosX)
//{
//	// 하나라도 마지막 or 0이하에 도달했다면 return
//	if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
//		return;
//
//	if (visited[x][y][cnt][prevPosX])
//		return;
//
//	int cur = map[x][y];
//	visited[x][y][cnt][prevPosX] = true;
//	// # 도착했다면 최종 결과를 저장
//
//	// 마지막 지점에 도착했을 때
//	if (x == n - 1 && y == m - 1) 
//	{
//		if (cur > prevPosX)
//			++result[cnt + 1];
//		else if (cur == 0)
//			++result[cnt];
//		return;
//	}
//
//	if (cur > 0 && cur <= prevPosX)
//		return;
//
//	// # 지난 방문했던 오락실보다 작은 오락실에 도착한다면 return
//	if(map[x][y] > 0)
//	{
//		// # 현재 도착한 오락실이 이전 오락실보다 등수가 높다면
//		if (IsVisited(x, y, prevPosX))
//		{
//			prevPosX = map[x][y];
//			cnt++;
//		}
//		else
//			return;
//	}
//
//	// 다음 위치로 이동
//	for (int i = 0; i < 2; i++)
//		DFS(x + dx[i], y + dy[i], cnt, prevPosX);
//}

void DFS()
{
	for(int i =0;i< n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k <= c; k++)
			{
				for (int l = 0; l <= c; l++)
				{
					int cur = visited[i][j][k][l];
					if (cur == 0) continue;

					for (int a = 0; a < 2; a++)
					{
						int cx = i + dx[a];
						int cy = j + dy[a];

						if (cx >= n || cy >= m) continue;
						int next = map[cx][cy];

						if (next == 0)
							visited[cx][cy][k][l] = (visited[cx][cy][k][l] + cur) % Dist;
						else if (next > l) 
							visited[cx][cy][k + 1][next] = (visited[cx][cy][k + 1][next] + cur) % Dist;
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &c);
	int a, b;
	int cnt = 0;
	for (int i = 0; i < c; i++)
	{
		scanf("%d %d", &a, &b);
		map[a-1][b -1] = ++cnt;
	}

	if (map[0][0] == 0)
		visited[0][0][0][0] = 1;
	else
	{
		int s = map[0][0];
		visited[0][0][1][s] = 1;
	}

	DFS();

	for (int k = 0; k <= c; ++k) 
	{
		int res = 0;
		for (int s = 0; s <= c; ++s)
			res = (res + visited[n - 1][m - 1][k][s]) % Dist;
		printf("%d ", res);
	}
}