#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m; 
vector<vector<int>> v;
vector<vector<int>> dp;

int DP(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m)
		return 0;

	if (n - 1 == x && m - 1 == y)
		return v[x][y];

	if (dp[x][y] != -1)
		return dp[x][y];

	int diagonal_move = 0, down_move = 0, right_move = 0;
	right_move = DP(x + 1, y) + v[x][y];
	down_move = DP(x, y + 1) + v[x][y];
	diagonal_move = DP(x + 1 , y + 1) + v[x][y];

	int max_value = 0;
	max_value = max(right_move, down_move);
	max_value = max(max_value, diagonal_move);
	dp[x][y] = max_value;
	return dp[x][y];

	
}
int main()
{
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	dp.resize(n, vector<int>(m, -1));
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
			cin >> v[x][y];
	}
	cout << DP(0, 0);
}