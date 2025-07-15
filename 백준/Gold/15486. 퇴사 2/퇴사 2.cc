#include<stdio.h>
#include<algorithm>
#include <vector>

using namespace std;

vector<int> dp;
vector<vector<int>> arr;

int main()
{
	int n;
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i].resize(2);

	for (int i = 0; i < n; i++)
	{
		int day, cost;
		scanf("%d %d", &day, &cost);
		arr[i][0] = day;
		arr[i][1] = cost;
	}

	dp.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
        // 1. 상담할 수 있다면, 수익 계산
        if (i + arr[i][0] <= n)
            dp[i + arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);

        // 2. 상담 안 하고 넘어가는 경우
        dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	int result = 0;
    for (int i = 0; i <= n; i++)
	    result = max(result, dp[i]);
	printf("%d", result);
}
