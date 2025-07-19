#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int n, k;

// TODO : 전역 변수는 자동 0초기화가 이뤄진다.

int main()
{
	scanf("%d %d", &n, &k);
	vector<int> v(n), dp(k + 1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
		dp[0] = 1;
	}

	for (int i = 1; i <= k; i++)
		dp[i] = (i % v[0] == 0) ? 1 : 0;
	// O(k)
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++) 
		{
			dp[j] = dp[j];
			if (j >= v[i])
				dp[j] = max(dp[j], dp[j] + dp[j - v[i]]);
		}
	}
	printf("%d", dp[k]);
}
