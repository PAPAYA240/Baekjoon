#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

// # priority queue < set 시간 복잡도
int N;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
vector<int> v;

int main()
{
	scanf("%d", &N);
	v.reserve(N);
	for (int i = 0; i < N; i++)
	{
		// # max의 top이 중간 값이 될 것이다.
		int num;
		scanf("%d", &num);

		// # max가 비어있거나 작으면 중간 값 유지를 위해 max에 저장
		if (maxHeap.empty() || maxHeap.top() >= num)
			maxHeap.push(num);
		else
			minHeap.push(num);

		// # 우선순위 힙의 왼쪽 - 오른쪽 트리의 최대 사이 높이는 1
		// # size_t는 **부호 없는 정수형 (unsigned)
		if (static_cast<int>(maxHeap.size()) - static_cast<int>(minHeap.size()) > 1)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (static_cast<int>(maxHeap.size()) - static_cast<int>(minHeap.size()) < 0)
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		v.emplace_back(maxHeap.top());
	}
	for(int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
}