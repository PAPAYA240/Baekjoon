#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int inputX, inputY, outputX, outputY;
vector<bool> visit;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;	
	visit.resize(N * M, false);
	int dFind[4] = { 1 , M, -1, -M };

	// 입력
	for (int i = 0; i < K; i++)
	{
		cin >> inputX >> inputY >> outputX >> outputY;

		int Xtype = inputX + (inputY * M);
		if (N * M <= inputX)
			continue;
		for (int j = 0; j < outputY - inputY; j++) // 0 
		{
			for (int k = 0; k < outputX - inputX; k++)
			{
				int Xrear = Xtype + k;
				visit[Xrear] = true;
			}
			Xtype += M;
		}
	}

	// 빈공간 BFS 탐색
	vector<int> Breath; // 넓이
	int cnt = 0; // 개수

	for (int x = 0; x < M * N; x++)
	{
		if (true == visit[x])
			continue;

		cnt++;
		queue<int> que;
		int currentBreath = 1;
		que.push(x);
		visit[x] = true;

		while (!que.empty())
		{
			int value = que.front();
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = value + dFind[i];

				// 범위를 넘어갔거나, 이미 방문했다면, ( 미래 값이 7의 배수(앞쪽 값)인데, 현재 값이 뒤쪽 값 일 때)
				if (0 > nx || nx >= M * N)
					continue;

				// 현재 수 끝 미래 수 앞
				if (0 == (nx % M) && 0 == (value + 1) % M)
					continue;

				if (0 == (value % M) && 0 == (nx + 1) % M)
					continue;

				if (true == visit[nx])
					continue;

				// 아직 방문하지 않았다면 넓이 가져오기
				que.push(nx);
				visit[nx] = true;
				++currentBreath;
			}
		}
		Breath.push_back(currentBreath);
	}
	
	cout << cnt << endl;
	sort(Breath.begin(), Breath.end());
	for (int i = 0; i < Breath.size(); i++)
	{
		cout << Breath[i] << ' ';
	}
}