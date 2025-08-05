#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1e9

using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> dp;
 
int main()
{
	// input
	cin >> n;
	v.resize(n, vector<int>(n));
	dp.resize(n, vector<int>(3, INF));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		dp[0][i] = v[0][i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				if (k == j)
					continue;

				if (dp[i][j] > dp[i - 1][k] + v[i][j])
					dp[i][j] = dp[i - 1][k] + v[i][j];
			}
		}
	}

	int result = INF;
	for (int i = 0; i < 3; i++)
		result = min(result, dp[n - 1][i]);
	cout << result;
}