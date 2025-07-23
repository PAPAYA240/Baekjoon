#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, result = 1;
	scanf("%d", &n);
	vector<int> v(n);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);
	}
	printf("%d", result);
}
