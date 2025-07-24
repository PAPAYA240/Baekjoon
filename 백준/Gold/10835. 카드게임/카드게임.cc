#include<stdio.h>
#include<vector>
#include<algorithm>

#define Left		0
#define Right	1

using namespace std;

int n, total = 0, result = 0;
vector<vector<int>> v(2);

void Recur(int _l, int _r, int _total)
{
	if (_l >= n || _r >= n)
	{
		result = max(result, _total);
		return;
	}

	// # 오른쪽이 더 작은 경우 오른쪽만 버린다. => 점수 추가
	if (v[Left][_l] > v[Right][_r])
		Recur(_l, _r + 1, _total + v[Right][_r]);

	// # 왼쪽만 버린다. => 점수 없음
	Recur(_l + 1, _r, _total);

	// # 둘 다 버린다 => 점수 없음
	Recur(_l + 1, _r + 1, _total);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < v.size(); i++)
		v[i].resize(n);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	}
	Recur(0, 0, total);
	printf("%d", result);
}