#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n ,1);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if(v[i] > v[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int result = -1;
	for (int i = 0; i < n; i++)
		result = max(result, dp[i]);

	cout << n - result;
}