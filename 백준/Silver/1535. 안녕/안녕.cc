#include<stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vec;
vector<int> dp;
int n;

int main()
{
	// # 입력
	scanf("%d", &n);
	vec.resize(n + 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i].first);
	for(int i = 0; i < n; i++)
		scanf("%d", &vec[i].second);

	dp.resize(101 , 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int hp = vec[i].first;
		int coin = vec[i].second;
		for (int j = 100; j >= hp + 1; j--)
		{
			dp[j] = max(dp[j], dp[j - hp] + coin);
		}
	}

	printf("%d", dp[100]);
}