#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
bool visited[9] = { false };
int arr[9] = {  };

void DFS(int idx)
{
	if (m == idx)
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

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[idx] = v[i];
			DFS(idx + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	DFS(0);
}