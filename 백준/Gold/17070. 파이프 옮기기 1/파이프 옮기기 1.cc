#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, cnt = 0;
vector<vector<int>> v;

enum SHAPE_TYPE { Horizon, Vertical, Diagonal };

bool isMove(SHAPE_TYPE type, int x, int y) 
{

	if (type == Horizon) 
	{
		if (y + 1 >= n ||  v[x][y + 1] == 1)
			return false;
	}
	else if (type == Vertical)
	{
		if (x + 1 >= n ||  v[x + 1][y] == 1)
			return false;
	}
	else 
	{
		if (x + 1 >= n || y + 1 >= n || v[x + 1][y] == 1 || v[x][y + 1] == 1 || v[x + 1][y + 1] == 1) 
			return false;
	}
	return true;
}

void BFS(int startX, int startY, SHAPE_TYPE startType)
{
	queue<pair<SHAPE_TYPE, pair<int, int>>> q;
	q.push({ startType, { startX, startY } });

	while (!q.empty())
	{
		int currentX = q.front().second.first;
		int currentY = q.front().second.second;
		SHAPE_TYPE currentType = q.front().first;
		q.pop();

		if (currentX == n - 1 && currentY == n - 1)
		{
			++cnt;
			continue;
		}

		if (currentType == Horizon)
		{
			if (isMove(Horizon, currentX, currentY))
				q.push({ Horizon, {currentX , currentY + 1 } });
		}

		else if (currentType == Vertical)
		{
			if (isMove(Vertical, currentX, currentY))
				q.push({ Vertical , { currentX + 1, currentY } });
		}

		else if (currentType == Diagonal)
		{
			if (isMove(Horizon, currentX, currentY))
				q.push({ Horizon, {currentX, currentY + 1} });
			if (isMove(Vertical, currentX, currentY))
				q.push({ Vertical , { currentX + 1 , currentY } });
		}

		if (isMove(Diagonal, currentX, currentY))
			q.push({ Diagonal, {currentX + 1, currentY + 1 } });
	}
}

int main()
{
	cin >> n;
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	BFS(0, 1, Horizon);
	cout << cnt;
}