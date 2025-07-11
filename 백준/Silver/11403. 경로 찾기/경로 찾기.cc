#include<iostream>
#include<cstring>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int map[101][101];
int resmap[101][101];
bool visited[101];
int n;
void DFS(int x)
{
	//	# 첫 열 x에 존재하는 부분에 대해서 for문을 돌린다
	// # 만약 x, i 가 전부 1이라면 방문 후에 i에 대한 행을 확인하여 깊이를 탐색한다.
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && map[x][i] == 1)
		{
			visited[i] = true;
			DFS(i);
		}
	}
}

int main()
{
	fastio();

	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >>map[i][j];

	for (int i = 0; i < n; i++)
	{
		memset(visited, false, 101);
		DFS(i);

		for (int k = 0; k < n; k++)
			if (visited[k] == true) 
				resmap[i][k] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(j != n -1)
		        cout << resmap[i][j] <<" ";
	        else
		        cout << resmap[i][j];
		}
		cout << "\n";
	}
	return 0;
}