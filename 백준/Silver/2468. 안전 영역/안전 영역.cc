#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, input;
queue<pair<int, int>> que;

int board[100][100];
int visit[100][100];

int dx[4] = { 1, 0, -1, 0 }; // x, 
int dy[4] = { 0, 1, 0, -1 }; // y, 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maxLevel = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			board[j][i] = input;
			if (maxLevel < input)
				maxLevel = input;
		}
	}

	int level = 1;
	int maxRegion = 0;

	while(level < maxLevel)
	{
		int region = 0;
		//초기화
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[j][i] = false;
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (level >= board[x][y] || visit[x][y])
					continue;

				que.push({x, y});
				++region;
				while (!que.empty())
				{
					pair<int, int> subPair = que.front();
					que.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = subPair.first + dx[i];
						int ny = subPair.second + dy[i];

						if (0 > nx || N <= nx || 0 > ny || N <= ny)
							continue;
						if (level >= board[nx][ny] || visit[nx][ny])
							continue;

						visit[nx][ny] = true;
						que.push({ nx, ny });
					}
				}
			}
		}

		if (maxRegion < region)
			maxRegion = region;
		++level;
	}
	
	if (maxRegion <= 0)
		maxRegion = 1;
	cout << maxRegion;
}