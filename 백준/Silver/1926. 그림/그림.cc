#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int X, Y, input;
queue<pair<int, int>> que;

int board[501][501];
bool Check[501][501];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cin >> input;
			board[i][j] = input;
		}
	}
	
	int area = 0;
	int max = 0;
	int cnt = 0;
	for (int x = 0; x < X; x++)
	{
		for (int y = 0; y < Y; y++)
		{
			// 첫 value 찾기
			if (0 == board[x][y] || true == Check[x][y])
				continue;

			// 만약 0도 아니고 방문도 안 했으면
			area = 1;
			cnt++; // 그림 하나 찾음
			que.push({ x, y });
			Check[x][y] = true;

			while (!que.empty())
			{
				pair<int, int> subPair = que.front();
				que.pop();

				// 주변 이웃 탐색
				for (int i = 0; i < 4; i++)
				{
					int idx = subPair.first + dx[i];
					int idy = subPair.second + dy[i];

					// 조건부 확인
					if (idx < 0 || idx >= X || idy < 0 || idy >= Y)
						continue;
					if (Check[idx][idy] || 0 == board[idx][idy])
						continue;

					area++;
					Check[idx][idy] = true;
					que.push({ idx, idy });
				}
				if (max < area)
					max = area;
			}
		}
	}
	cout << cnt << '\n' << max;
}