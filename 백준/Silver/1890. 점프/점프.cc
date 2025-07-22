#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<long long>> dp, vec;

int dx[2] = { 0 , 1 };
int dy[2] = { 1 , 0 };

long long DFS(int x, int y)
{
	if (x == n - 1 && y == n - 1)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];

	if (vec[x][y] == 0)
		return 0;
	

	dp[x][y] = 0;
	int jump = vec[x][y];
	for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
	{
		int nx = x + jump * dx[i];
		int ny = y + jump * dy[i];
		if (nx >= n || ny >= n || nx < 0 || ny < 0)
			continue;

		dp[x][y] += DFS(nx, ny);
	}
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);

	vec.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++)
	{
		vec[i].resize(n);
		dp[i].resize(n, -1);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &vec[i][j]);

	printf("%lld", DFS(0, 0));
}