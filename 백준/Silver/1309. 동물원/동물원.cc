#include<iostream>
#include<vector>

#define MOD  9901
using namespace std;
int n;
vector<vector<int>> v;

int main()
{
	cin >> n;
	v.resize(n + 1, vector<int>(3));
	v[1][0] = 1; // 두칸 모두 빈 상태
	v[1][1] = 1; // 왼쪽 칸 이 찬 상태
	v[1][2] = 1; // 오른쪽 칸이 찬 상태

	for (int i = 2; i <= n; i++)
	{
		// 두 칸 모두 비울 상태
		v[i][0] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2]) % MOD;
		// 왼쪽한 칸만 채운 상태
		v[i][1] = (v[i - 1][0] + v[i - 1][2]) % MOD;
		// 오른쪽 칸만 채운 상태
		v[i][2] = (v[i - 1][0] + v[i - 1][1]) % MOD;
	}

	int total = (v[n][0] + v[n][1] + v[n][2]) % MOD;
	cout << total;
}