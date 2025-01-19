#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int main()
{
	// 각 객체의 최대를 구함
	// 파라메트릭 정렬
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> vec;
	cin >> N >> M;
	
	long long start = 1;
	long long end = 0;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		vec.emplace_back(input);
		end += input;
	}
	sort(vec.begin(), vec.end());

	long long result = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (mid < vec[i])
				sum += vec[i] - mid;
		}

		// 남은 값이 가져가려는 값보다 작다면
		if (sum < M)
		{
			end = mid - 1;
		}
		// 남은 값이 가져가려는 값보다 크다면
		else if (sum >= M)
		{
			result = mid; // 최대를 도출해낼 것이기 때문에
			start = mid + 1;
		}
	}

	cout << result << endl;
}
