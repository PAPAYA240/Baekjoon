#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int R, C;
char Map[51][51];
int Visited[51][51];

queue<pair<int, int>> queS;
queue<pair<int, int>> queW;
pair<int, int> destination;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void Input()
{
	cin >> R >> C;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> Map[x][y];

			// Water
			if (Map[x][y] == '*')
				queW.push(make_pair(x, y));

			// Destination
			else if (Map[x][y] == 'D')
			{
				destination.first = x;
				destination.second = y;
			}

			// Start Point
			else if (Map[x][y] == 'S')
				queS.push(make_pair(x, y));
		}
	}
}

void Check()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << Visited[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << Map[j][i] << ' ';
		}
		cout << endl;
	}
}

void BFS(pair<int, int> value)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = value.first + dx[i];
		int ny = value.second + dy[i];

		// 범위 내에 존재 하지 않으면 continue;
		if (nx < 0 || ny < 0 || nx >= C || ny >= R)
			continue;

		// 이미 방문 했다면 continue;
		if (0 != Visited[nx][ny])
			continue;

		// 만약 빈 공간일 때
		if ('.' == Map[nx][ny])
		{
			Visited[nx][ny] = Visited[value.first][value.second] + 1;
			// 혹은 물이라면
			if ('*' == Map[value.first][value.second])
			{
				Map[nx][ny] = '*';
				queW.push(make_pair(nx, ny));
			}
			// 고슴도치가 움직이려 한다면
			if ('S' == Map[value.first][value.second])
			{
				Map[nx][ny] = 'S';
				queS.push(make_pair(nx, ny));
			}
			
			// Check();
		}

		if(Map[nx][ny] == 'D')
		{
			if (Map[value.first][value.second] == 'S')
			{
				queS.push(make_pair(nx, ny));
				Visited[nx][ny] = Visited[value.first][value.second] + 1;
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	Input();

	// bfs
	while(!queS.empty() || !queW.empty())
	{
		// 물에 있는 것들부터 판별
		queue<pair<int, int>> sub;
		sub = queW;
		while(!sub.empty())
		{
			queW.pop();
			BFS(sub.front());
			sub.pop();

		}

		queue<pair<int, int>> subS;
		subS = queS;
		while(!subS.empty())
		{
			queS.pop();
			BFS(subS.front());
			subS.pop();
		}
	}

	// output
	if(0 == Visited[destination.first][destination.second])
		cout << "KAKTUS" << endl;
	else
		cout << Visited[destination.first][destination.second] << endl;

}