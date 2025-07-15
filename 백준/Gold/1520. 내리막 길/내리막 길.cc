#include<stdio.h>
#include<vector>
#include <algorithm>

using namespace std;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

vector<vector<int>> vec;
vector<vector<int>> dp;

int n, m;


int DFS(int x, int y)
{
	// # 목적지 탐색 완료
	if (x == n - 1 && y == m - 1)
		return 1;

	// # DP 활용
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	// # 주변 경로 탐색
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// # 탐색할 수 없는 경로라면
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (vec[nx][ny] < vec[x][y])
			dp[x][y] += DFS(nx, ny);
	}

	// # 탐색이 전부 끝났고 더이상 탐색할 곳이 없다면
	return dp[x][y];
}

int main()
{
	// # 입력
	scanf("%d %d", &n, &m);
	vec.resize(n + 1);
	dp.resize(n + 1);
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].resize(m, 0);
		dp[i].resize(m, -1);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &vec[i][j]);

	// # DFS 재귀
	DFS(0, 0);

	// # 출력
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result = max(result, dp[i][j]);

	printf("%d", result);
}