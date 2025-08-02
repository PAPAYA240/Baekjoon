#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> dp;
long long result = 1;
bool isSame(int idx)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == idx)
			return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	v.resize(m + 1);
	dp.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isSame(i))
		{
			result *= dp[idx];
			idx = 0;
			continue;
		}
		++idx;
	}
	cout << (result * dp[idx]);
}