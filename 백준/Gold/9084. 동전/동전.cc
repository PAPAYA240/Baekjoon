#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
vector<vector<int>> dp;
vector<int> vec;
vector<int> res;

void reset()
{
	dp.clear();
	dp.shrink_to_fit();

	vec.clear();
	vec.shrink_to_fit();
}

int main()
{
	// # 입력
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		vec.resize(n);
		res.reserve(t);

		for (int i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		scanf("%d", &m);
		dp.resize(n);
		for (int i = 0; i < n; i++)
			dp[i].resize(m + 1);

		// # 첫 번째는 배수로
		for(int i = 0; i < n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= m; i++)
			dp[0][i] = (i % vec[0] == 0) ? 1 : 0;
		// # 두 번째는 첫 번째 배열을 기반으로
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				// # 현재 머니가 동전보다 크거나 같다면
				if (j >= vec[i])
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j] + dp[i][j - vec[i]]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		res.emplace_back(dp[n - 1][m]);
		reset();
	}
	for(int i = 0 ; i < res.size(); i++)
		printf("%d\n", res[i]);
}