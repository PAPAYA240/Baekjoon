#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
// DFS 활용

int T, N, M, K;

int arr[51][51];
bool visit[51][51];

stack<pair<int, int>>	stk;
vector<int> result;

int dx[4] = { 1, 0, -1 , 0 };
int dy[4] = { 0, 1, 0 , -1 };

int DFS()
{
	int cnt = 0;
	for (int y = 0; y <= M; y++)
	{
		for (int x = 0; x <= N; x++)
		{
			if (visit[x][y] || 0 == arr[x][y])
				continue;

			stk.push({ x, y });
			visit[x][y] = true;

			++cnt;
			while (!stk.empty())
			{
				pair<int, int> value = stk.top();
				stk.pop();

				for (int i = 0; i < 4; i++)
				{
					int nx = value.first + dx[i];
					int ny = value.second + dy[i];

					if (nx < 0 || ny < 0 || nx > N || ny > M)
						continue;

					if (visit[nx][ny] || 0 == arr[nx][ny])
						continue;

					visit[nx][ny] = true;
					stk.push({ nx, ny });
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for(int j = 0; j < T; j++)
	{
		// 초기화
		for(int i = 0; i < 51; i++)
		{
			for (int k = 0; k < 51; k++)
			{
				arr[k][i] = 0;
				visit[k][i] = false;
			}
		}

		// 입력
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		// 출력
		result.push_back(DFS());
	}

	for(const auto& iter : result)
		cout << iter << endl;
}