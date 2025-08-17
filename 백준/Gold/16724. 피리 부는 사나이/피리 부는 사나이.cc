#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<char>> v;
int _Count = 0;

void Recur(int x, int y, int group_num)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return;

	if (map[y][x] != 0) 
	{
		if (map[y][x] == group_num) 
			_Count++;
		return;
	}

	map[y][x] = group_num;

	if ('D' == v[y][x])		Recur(x, y + 1, group_num);
	else if ('L' == v[y][x])	Recur(x - 1, y, group_num);
	else if ('R' == v[y][x])	Recur(x + 1, y, group_num);
	else if ('U' == v[y][x])	Recur(x, y - 1, group_num);
}


int main()
{
	cin >> n >> m;
	v.resize(n);
	map.resize(n, vector<int>(m));

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			v[i].emplace_back(str[j]);
	}

	int group_id = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				group_id++;
				Recur(j, i, group_id);
			}
		}
	}
	cout << _Count;
}
