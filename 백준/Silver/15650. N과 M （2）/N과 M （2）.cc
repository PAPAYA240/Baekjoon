#include<iostream>
using namespace std;

int arr[9];
bool visited[9] = { false };
int n, m;

void DFS(int currentNum, int idx)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
        {
            if (i == m - 1)
		        cout << arr[i];
	        else
		        cout << arr[i] << ' ';
        }
		cout << '\n';
		return;
	}

	for (int i = currentNum ; i <= n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		arr[idx] = i;
		DFS(i + 1, idx + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	if (m <= 1)
	{
		for (int i = 1; i <= n; i++)
			cout << i << '\n';
		return 0;
	}

	DFS(1, 0);
}