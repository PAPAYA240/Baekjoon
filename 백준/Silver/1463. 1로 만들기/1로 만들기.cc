#include <stdio.h>
#include<algorithm>
using namespace std;

int dp[10000001];

int main()
{
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}
	printf("%lld", dp[n]);
	return 0;
}