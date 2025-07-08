#include<iostream>

using namespace std;

int arr[2500][2500] = {};
bool visited[2500][2500] = { false };
int n;
int iZero = 0, iMinus = 0, iPlus = 0;

void Judg(int x, int y, int curN)
{
	if (visited[x][y])
		return;

	int current = arr[x][y];

	bool bResult = true;
	for (int i = x; i < x + curN; i++)
	{
		for (int j = y; j < y + curN; j++)
		{
			if (current != arr[i][j])
			{
				bResult = false;
				break;
			}
		}
	}

	if (bResult)
	{
		for (int i = x; i < x + curN; i++)
			for (int j = y; j < y + curN; j++)
				visited[i][j] = true;

		if (current == 0)
			++iZero;
		else if (current == 1)
			++iPlus;
		else
			++iMinus;

		return;
	}
	else
	{
		for (int i = x; i < x + curN; i++)
			for (int j = y; j < y + curN; j++)
				Judg(i, j, curN / 3);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			Judg(i , j, n);

	cout << iMinus << endl;
	cout << iZero << endl;
	cout << iPlus << endl;
}

