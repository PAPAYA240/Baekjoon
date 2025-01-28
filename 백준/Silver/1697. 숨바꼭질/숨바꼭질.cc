#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100000
using namespace std;
int N, K;

queue<pair<int, int>> que;
bool array_t[100001] = { false };

int BFS()
{
	if (N == K)
		return 0;

	while (!que.empty())
	{
		pair<int, int> value = que.front();
		que.pop();

		int A = value.first + 1;
		int B = value.first - 1;
		int C = value.first * 2;

		if(MAX >= A && 0 <= A && false == array_t[A])
		{
			que.push({ A, value.second + 1 });
			array_t[A] = true;
		}
		if (MAX >= B && 0 <= B && false == array_t[B])
		{
			que.push({ B, value.second + 1 });
			array_t[B] = true;
		}
		if (MAX >= C && 0 <= C && false == array_t[C])
		{
			que.push({ C, value.second + 1 });
			array_t[C] = true;
		}

		if (A == K || B == K || C == K)
			return value.second + 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	que.push({N, 0});

	cout << BFS();
}