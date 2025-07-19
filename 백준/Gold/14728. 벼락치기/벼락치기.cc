#include<stdio.h>
#include<algorithm>
#include<vector>

#define INF 1e9 
using namespace std;

int n, k, total = 0;
vector<int> w, v;
// dp : 가치 v를 얻기 위한 최소한의 무게
int main()
{
	// #입력
	scanf("%d %d", &n, &k);
	w.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
		total += v[i]; 
	}

	vector<int> dp(total + 1, INF);
	dp[0] = 0;
	// # 누적 값 계산
	for (int i = 0; i < n; i++)
	{
		for (int j = total; j >= v[i]; j--)
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]); // j 무게에서 i 물건을 선택했을 때의 무게
	}
	int answer = 0;
	for (int i = 0; i <= total; i++)
	{
		if (dp[i] <= k)
			answer = max(answer, i); // 최대 가치
	}
	printf("%d\n", answer);
}