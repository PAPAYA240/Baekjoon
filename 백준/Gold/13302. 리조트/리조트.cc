#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> noday;
vector<vector<int>> dp;

bool Noday(int _curday)
{
	for (int i = 0; i < noday.size(); i++)
		if (noday[i] == _curday)
			return true;
	return false;
}

int Recur(int _day, int _sale)
{
	// # 여름 방학이 지났다면
	if (_day > n)
		return 0;

	// # 이미 누적한 값이 존재한다면
	if (dp[_day][_sale] != 1e9)
		return dp[_day][_sale];
	
	// # 갈 수 없는 날에 돈을 내야 한다면 그냥 지나가기
	if (Noday(_day) == true)
	{
		dp[_day][_sale] = Recur(_day + 1, _sale);
	}
	else
	{
		int scaleCost = 1e9;
		if (_sale >= 3)
			scaleCost = Recur(_day + 1, _sale - 3);

		dp[_day][_sale] = min(Recur(_day + 1, _sale) + 10000, Recur(_day + 3, _sale + 1) + 25000);
		dp[_day][_sale] = min(dp[_day][_sale], Recur(_day + 5, _sale + 2) + 37000);
		dp[_day][_sale] = min(dp[_day][_sale], scaleCost);
	}
	return dp[_day][_sale];
}

int main()
{
	scanf("%d %d", &n, &m);
	noday.resize(m);
	dp.resize(n + 1);
	for (int i = 0; i < dp.size(); i++)
		dp[i].resize(101, 1e9);

	for (int i = 0; i < m; i++)
		scanf("%d", &noday[i]);
	printf("%d", Recur(1, 0));
}