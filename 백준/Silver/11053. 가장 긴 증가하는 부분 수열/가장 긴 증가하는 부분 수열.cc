#include<iostream>
#include<vector>
using namespace std;

int dp[1001];
int arr[1001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] < arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	cout << result;
}