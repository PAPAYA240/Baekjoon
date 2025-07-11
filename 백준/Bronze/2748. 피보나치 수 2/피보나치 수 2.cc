#include <stdio.h>

using namespace std;

long long dp[91];

int main()
{
	int n;
	scanf("%lld", &n);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i -1] + dp[i - 2];

	printf("%lld", dp[n]);
	return 0;
}