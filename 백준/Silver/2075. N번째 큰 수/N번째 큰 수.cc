#include<stdio.h>
#include<queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	// # 입력
	scanf("%d", &N);
	for (int i = 0; i < N * N; i++)
	{
		int a;
		scanf("%d", &a);
		pq.push(a);
		
		// # 메모리 초과 방지 : pq의 개수가 n이 넘는다면 필요 없는 가장 작은 부분을 계속 없앤다.
		if (pq.size() > N)
			pq.pop();
	}

	// # 출력
	printf("%d", pq.top());
}