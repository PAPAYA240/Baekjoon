#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int main()
{
	// # 입력
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		pq.push(a);
	}

	while (pq.size() > 1)
	{
		int result = 0;
		// # 비교
		for(int i = 0; i < 2; i++)
		{
			result += pq.top();
			pq.pop();
		}
		// # 값 저장
		v.emplace_back(result);
		pq.push(result);
	}

	// # 출력
	int result = 0;
	for (int i = 0; i < v.size(); i++)
		result += v[i];
	printf("%d", result);
}
