
#include<iostream>
#include<vector>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
vector<vector<int>> v;
int result[3] = { 0 };

bool Is_All_Same(int x, int y, int maxX, int maxY)
{
	int cnt = v[x][y];
	for (int i = x; i < maxX; i++)
	{
		for (int j = y; j < maxY; j++)
		{
			if (v[x][y] != v[i][j])
				return false;
		}
	}

	return true;
}

// 현재 위치, 마지막 위치
void Judg(int x, int y, int maxX, int maxY)
{
	// # 같다면
	if (Is_All_Same(x, y, maxX, maxY))
	{
		++result[v[x][y] + 1];
		return;
	}
	

	// # 같지 않다면
	int divide = (maxX - x) / 3; // 한 변을 나눈다.
		for (int i = x; i < maxX; i += divide)
		for (int j = y; j < maxY; j += divide)
			Judg(i, j, i + divide, j + divide);
}

int main()
{
	fastio();

	int n;
	cin >> n;

	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	 Judg(0 , 0, n, n);

	 for (int i = 0; i < 3; i++)
		 cout << result[i] << endl;
}

