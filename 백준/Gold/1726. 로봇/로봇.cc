#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define MAX_NUM 99999
#define MAX_DIR 3
#define ROTATION_NUM 0
#define STRIGHT_NUM 1
#define MOVE_NUM 2

using namespace std;

struct Robot
{
	int direction;
	int directX;
	int directY;
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> moves = {
		{0, 2, 1, 1}, 
		{2, 0, 1, 1}, 
		{1, 1, 0, 2}, 
		{1, 1, 2, 0}  
};

int N, M;

int Map[1000][1000];
int SubMap[1000][1000];
bool visited[1000][1000];

Robot robot;
Robot destination;

queue<tuple<int, int, tuple<int, int, int>>> que;

int minDist = MAX_NUM;

void CheckMap(int x, int y, tuple<int, int, int> infoValue)
{
	if(SubMap[x][y] > get<MOVE_NUM>(infoValue) || 0 == SubMap[x][y])
		SubMap[x][y] = get<MOVE_NUM>(infoValue);

	/*cout << endl;
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << SubMap[x][y] << ' ';
		}
		cout << endl;
	}*/
}

// 지나가는 최소 길 확인하고, 회전 수 확인
void Input()
{
	// 맵 구성
	cin >> M >> N;
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> Map[x][y];
			Map[x][y] = abs(Map[x][y] - 1);
		}
	}
	// 출발지
	cin >> robot.directY >> robot.directX >> robot.direction;
	// 도착지
	cin >> destination.directY >> destination.directX >> destination.direction;

	destination.directX -= 1;
	destination.directY -= 1;
	robot.directX -= 1;
	robot.directY -= 1;

	// x, y ,(rotation, stright, moveNumber)
	que.push(make_tuple(robot.directX, robot.directY, make_tuple(robot.direction, 0, 0)));
}

// 턴 판단
int JudgmentTurn(pair<int, int> _currentPos, pair<int, int> _futurePos)
{
	// 동
	if (_futurePos.second == _currentPos.second && _futurePos.first == _currentPos.first + 1)
		return 1;
	// 서
	if (_futurePos.second == _currentPos.second && _futurePos.first + 1 == _currentPos.first)
		return 2;

	// 남
	if (_futurePos.first == _currentPos.first && _futurePos.second  == _currentPos.second + 1)
		return 3;
	// 북
	if (_futurePos.first == _currentPos.first && _futurePos.second + 1 == _currentPos.second)
		return 4;

	// 그대로
	return 0;
}

int BFS()
{
	if (destination.directX == robot.directX && destination.directY == robot.directY)
	{
		int _val = moves[robot.direction - 1][destination.direction - 1];
		return _val;
	}

	while (!que.empty())
	{
		// 1. Go Stright
		tuple<int, int, tuple<int, int, int>> value = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = get<0>(value) + dx[i];
			int ny = get<1>(value) + dy[i];

			tuple<int, int, int> infoValue = get<2>(value);

			// 범위 체크
			if (nx < 0 || ny < 0 || nx > N || ny > M)		
				continue;

			// 할당 체크
			if (0 == Map[nx][ny])			
				continue;

			if (get<MOVE_NUM>(infoValue) > SubMap[nx][ny])
				continue;

			// 3번 이상 앞으로 갔다면
			if (3 < get<STRIGHT_NUM>(infoValue))
			{
				// 처음부터 다시
				++get<MOVE_NUM>(infoValue);
				// 초기화
				get<STRIGHT_NUM>(infoValue) = 1;
			}

			int TurnNumber = JudgmentTurn(make_pair(get<0>(value), get<1>(value)), make_pair(nx, ny));
			// 회전 할 때
			if (get<ROTATION_NUM>(infoValue) != TurnNumber)		
			{
				get<STRIGHT_NUM>(infoValue) = 1;
				get<MOVE_NUM>(infoValue) += (1 + moves[TurnNumber - 1][get<ROTATION_NUM>(infoValue) - 1]);
			}
			// 회전하지 않고 앞으로 갈 때
			else
			{
				++get<STRIGHT_NUM>(infoValue);
				if (1 == get<STRIGHT_NUM>(infoValue))
					get<MOVE_NUM>(infoValue) += 1;
			}

			// 정답이라면
			get<ROTATION_NUM>(infoValue) = TurnNumber;
			if (nx== destination.directX && ny == destination.directY)
			{
				// 한 번 더 Stright 도 확인
				if (3 < get<STRIGHT_NUM>(infoValue))
				{
					// 넘었다면 Move up
					++get<MOVE_NUM>(infoValue);
					// 초기화
					get<STRIGHT_NUM>(infoValue) = 1;
				}

				// 한 번 더 회전 확인
				int _val = moves[get<ROTATION_NUM>(infoValue) - 1][destination.direction - 1]/*(get<ROTATION_NUM>(infoValue) == destination.direction) ? 0 : 1*/;
				get<MOVE_NUM>(infoValue) += (_val);

				// 가장 적은 값을 할당
				if(minDist > get<MOVE_NUM>(infoValue))
					minDist = get<MOVE_NUM>(infoValue);

				break;
			}

			CheckMap(nx, ny, infoValue);
			que.push(make_tuple(nx, ny, infoValue));

		}
		visited[get<0>(value)][get<1>(value)] = true;
	}

	if (MAX_NUM == minDist)
		minDist = 0;

	return minDist;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(&SubMap[0][0], &SubMap[0][0] + sizeof(SubMap) / sizeof(SubMap[0][0]), 9999);

	Input();

	cout << BFS() << endl;

	return 0;
}
