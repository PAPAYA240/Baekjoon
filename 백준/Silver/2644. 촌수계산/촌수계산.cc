#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Releation
{
	int parents = 0;
	int child = 0;
};

int N, M, A, B = 0;
vector<Releation> ReleationVec;
vector<int> kinship;
queue<int> que;

void BFS()
{
	que.push(A);
	kinship[A] = 0;

	while (!que.empty())
	{
		int value = que.front();
		que.pop();

		for (auto& iter : ReleationVec)
		{
			if (iter.child == value && -1 == kinship[iter.parents])
			{
				kinship[iter.parents] = kinship[iter.child] + 1;
				que.push(iter.parents);
			}
			else if (iter.parents == value && -1 == kinship[iter.child])
			{
				kinship[iter.child] = kinship[iter.parents] + 1;
				que.push(iter.child);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. 전체 사람 수 
	// 2. 촌수 계산 대상
	// 3. 부모 자식 간 관계 개수
	cin >> N >> A >> B >> M;
	kinship.resize(N + 1, -1);
	kinship.push_back(A);

	for (int i = 0; i < M; i++)
	{
		Releation rel = {};
		cin >> rel.parents >> rel.child;
		ReleationVec.push_back(rel);
	}
	BFS();
	cout << kinship[B] << endl;
	return 0;
}