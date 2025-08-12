#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1e9
using namespace std;

int n;
int dp[1001][3][3];
int v[1001][3];

int DP(int x, int y, int color)
{
	if (y == n - 1)
	{
		if (x == color)
			return INF;
		else
			return v[y][x];
	}

	if (INF != dp[y][x][color])
		return dp[y][x][color];

	for (int i = 0; i < 3; i++)
	{
		if (i == x)
			continue;

		dp[y][x][color] = min(dp[y][x][color], v[y][x] + DP(i, y + 1, color));
	}
	return dp[y][x][color];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> v[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	int result = INF;
	for (int i = 0; i < 3; i++)
		result = min(result, DP(i, 0, i));
	cout << result;
}