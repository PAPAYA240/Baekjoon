#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int N = 6;
const int M = 12;

char Map[7][13];
bool visited[7][13];

queue<pair<int, int>> que;
vector<pair<int, int>> PopVec;

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int AllSize = { 0 };

void Input()
{
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> Map[x][y];
		}
	}
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second; 
}

void MapCheck()
{
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Map[j][i];
		}
		cout << endl;
	}
}

void ChangeValue()
{
	++AllSize;
	sort(PopVec.begin(), PopVec.end(), compare);
	while(!PopVec.empty())
	{
		for(int i = 0; i <= M; i++)
		{
			int x = PopVec.back().first;
			int y = PopVec.back().second;
			Map[x][y] = '.';
		}
		PopVec.pop_back();
	}

	// 내리기
	for (int y = M - 1; y >= 0; y--)
	{
		for (int x = 0; x < N; x++)
		{
			if(Map[x][y] != '.')
			{
				for (int i = y; i < M; i++)
				{
					if (Map[x][i + 1] == '.')
					{
						Map[x][i + 1] = Map[x][i];
						Map[x][i] = '.';
					}
					else
						break;
				}
			}
		}
	}
}

void BFS()
{
	vector<pair<int, int>> vec;
	while (!que.empty())
	{
		pair<int, int> value = que.front();
		que.pop();

		for (int i = 0; i < 5; i++)
		{
			int nx = value.first + dx[i];
			int ny = value.second + dy[i];

			// 범위를 넘어섰다면 continue;
			if (0 > nx || 0 > ny || nx >= N || ny >= M)
				continue;

			// 같은 색이 아니라면
			if (Map[value.first][value.second] != Map[nx][ny])
				continue;

			// 이미 방문한 곳이라면
			if (visited[nx][ny])
				continue;

			vec.push_back(make_pair(nx, ny));
			visited[nx][ny] = true;
			que.push(make_pair(nx, ny));
		}
	}

	if (vec.size() >= 4)
	{
		for (const auto& iter : vec)
			PopVec.push_back(iter);

		while (!que.empty())
			que.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Input
	Input();
	
	int a = 0;

	// BFS
	while(a < N * M)
	{
		++a;
		for (int y = M - 1; y >= 0; y--)
		{
			for (int x = 0; x < N; x++)
			{
				if (Map[x][y] != '\0' && Map[x][y] != '.')
				{
					que.push({ x, y });
					BFS();
				}
			}
		}

		// 자리 덮어 씌우기
		while (!PopVec.empty())
			ChangeValue();
		fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(visited[0][0]), false);
		
		// MapCheck();
	}
	cout << AllSize << endl;
}