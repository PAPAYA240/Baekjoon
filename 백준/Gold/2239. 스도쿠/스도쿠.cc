#include<iostream>
#include<vector>
#include<string>

using namespace std;

int v[9][9];
bool Find(int x, int y, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (v[y][i] == num)
			return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (v[i][x] == num)
			return false;
	}

	int start_row = (y / 3) * 3;
	int start_col = (x / 3) * 3;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (v[start_row + i][start_col + j] == num) 
				return false;
		}
	}
    return true;
}

bool BackTracking()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (v[i][j] != 0)
				continue;

			for (int num = 1; num <= 9; num++)
			{
				if (Find(j, i, num))
				{
					v[i][j] = num;

					if (BackTracking())
						return true;
				}
				v[i][j] = 0;
			}
			return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 9; j++)
			v[i][j] = str[j] - '0';
	}
	BackTracking();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}
}