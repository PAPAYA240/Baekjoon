#include <iostream>
#include <vector>
#include <algorithm>

// 문제 와파기기 설치 위치는 
// 공평한 거리를 유지하면서 가장 넓은 거리를 도출할 것 

using namespace std;

int N, C;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vecPos;
	int result = 0;

	cin >> N >> C;
	
	for (int i = 0; i < N; i++)
	{
		int insert;
		cin >> insert;
		vecPos.emplace_back(insert);
	}

	sort(vecPos.begin(), vecPos.end());
	long long start = 1;
	long long end = vecPos[N - 1] - vecPos[0];
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int maxDist = 0;
		int install = 1;

		int type = vecPos[0];
		for (int i = 0; i < N - 1; i++)
		{
			int dist = vecPos[i + 1] - type;
			// mid보다 dist가 크다
			if (dist >= mid)
			{
				install++;
				type = vecPos[i+1];
			}
		}

		// 설치 예정보다 더 많으면
		if (install >= C)
		{
			start = mid + 1;
			result = mid;
		}
		else if (install < C)
		{
			 end = mid - 1;
		}
	}
	cout << result;
}