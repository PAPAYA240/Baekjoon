#include <iostream>
#include <vector>
#include <algorithm>

// 강의 길이를 합쳤을 때 3개가 나와야 하고 
// 그 중에서 가장 큰 값을 도출해야 함

using namespace std;

int N, M, input;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec;
	long long end = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		vec.emplace_back(input);
		end += input;
	}

	long long start = 0;
	long long MaxResult = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;

		long long maxCnt = 0;
		long long Cnt = 0;
		for (int i = 0; i < N; i++)
		{
			maxCnt += vec[i];
			if (maxCnt >= mid)
			{
				if (mid <= vec[i])
				{
					sort(vec.begin(), vec.end());
					cout << vec[N - 1];
					return 0;
				}

				maxCnt -= vec[i];
				--i;
				maxCnt = 0;
				++Cnt;
			}
		}
		// cnt가 M보다 작으면
		if (Cnt < M)
		{
			end = mid - 1;
		}
		//cnt가 M보다 크면
		else if (Cnt >= M)
		{
			start = mid + 1;
			MaxResult = mid;
		}
	}
	cout << MaxResult;
}