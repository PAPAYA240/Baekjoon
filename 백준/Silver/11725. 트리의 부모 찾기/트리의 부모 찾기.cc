#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> arr;
vector<int> parent;
int n;

void BFS()
{
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();
		for (auto iter : arr[currentNode])
		{
			if (parent[iter] == 0)
			{
				parent[iter] = currentNode;
				q.push(iter);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;
	int a, b;
	arr.resize(n + 1);
	parent.resize(n + 1);
	for (int i = 0; i < n -1; i++)
	{
		cin >> a >> b;
		arr[a].emplace_back(b);
		arr[b].emplace_back(a);
	}

	BFS();
	for (int i = 2; i <= n; i++)
		cout << parent[i]<< '\n';
}