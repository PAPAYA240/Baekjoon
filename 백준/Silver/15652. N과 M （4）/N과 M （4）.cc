#include<iostream>

using namespace std;

int n, m;
int arr[9];

void DFS(int currentNum, int idx)
{
	if (m == idx)
	{
		for (int i = 0; i < m; i++)
		{
			if(i == m - 1)
				cout << arr[i];
			else
				cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = currentNum; i <= n; i++)
	{
		arr[idx] = i;
		DFS(i, idx + 1);
	}

}

int main()
{
	cin >> n >> m;
	DFS(1, 0);
}