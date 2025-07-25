#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<vector<int>>> dp;
int rule[3] = {0, 1, 2};
int n;

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

bool Valid(int _x, int _y)
{
	return (_x < n && _y < n);
}

int Recur(int _x, int _y, int _rulecnt)
{
    	// # 누적 값이라면
    if (dp[_x][_y][_rulecnt % 3] != -1)
    	return dp[_x][_y][_rulecnt % 3];
    
    int maxMilk = 0;
    int currentMilk = 0;
    // # 마시지 않고 지나칠 경우의 최댓값
    for (int i = 0; i < 2; i++)
    {
    	int nx = _x + dx[i];
    	int ny = _y + dy[i];
    	if (Valid(nx, ny))
    		currentMilk = max(currentMilk, Recur(nx, ny, _rulecnt));
    }
    
    // 마신 경우
    if (v[_x][_y] == rule[_rulecnt % 3])
    {
    	for (int i = 0; i < 2; i++)
    	{
    		int nx = _x + dx[i];
    		int ny = _y + dy[i];
    		if (Valid(nx, ny))
    			maxMilk = max(maxMilk, Recur(nx, ny, _rulecnt + 1));
    	}
    	currentMilk = max(currentMilk, maxMilk + 1);
    }
    dp[_x][_y][_rulecnt % 3] = currentMilk;
    
    return dp[_x][_y][_rulecnt % 3];
}

int main()
{
	scanf("%d", &n);
    if (0 == n)
	{
		printf("%d", 0);
		return 0;
	}
	v.resize(n, vector<int>(n));
	dp.resize(n, vector<vector<int>>(n, vector<int>(3, -1)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	printf("%d", Recur(0, 0, 0));
}