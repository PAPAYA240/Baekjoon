#include<stdio.h>
#include<vector>
#include<algorithm>

#define Left	0
#define Right	1

using namespace std;

int n, result = 0;
vector<vector<int>> v(2);
vector<vector<int>> dp;

int Recur(int _l, int _r)
{
	// # 어느 한 카드가 끝까지 갔다면
	if (_l >= n || _r >= n)
		return 0;

	// # 이미 계산된 값이 있다면
	if (dp[_l][_r] != -1)
		return dp[_l][_r];
	
	// # 오른쪽이 더 작은 경우 오른쪽만 버린다. => 점수 추가
	if (v[Left][_l] > v[Right][_r])
		dp[_l][_r] =  v[Right][_r] + Recur(_l, _r + 1);
	else
	{
		// # 왼쪽만 버린다. => 점수 없음
		int scoreA = Recur(_l + 1, _r);

		// # 둘 다 버린다 => 점수 없음
		int scoreB= Recur(_l + 1, _r + 1);
		dp[_l][_r] = max(scoreA, scoreB);
	}	
	return dp[_l][_r];
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < 2; i++)
		v[i].resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++)
		dp[i].resize(n, -1);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	}
	printf("%d", Recur(0, 0));
}