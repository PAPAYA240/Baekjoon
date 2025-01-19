#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, input;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		sum += input;
		vec.push_back(input);
	}
	cin >> M;
	
	// 1. 모든 요청이 배정될 수 있는 경우
	if (sum <= M)
	{
		sort(vec.begin(), vec.end());
		cout << vec[N - 1];
		return 0;
	}

	// 2. 모든 요청이 배정될 수 없는 경우
	long long start = 1, end = M;
	int result = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long resting = M;

		int max = 0;
		for (int i = 0; i < N; i++)
		{
			int Minus = 0;
			if(vec[i] <= mid)
				Minus = vec[i];
			else
				Minus = mid;

			resting -= Minus;
			if (max < Minus)
				max = Minus;
		}

		// 남은 게 M보다 적다면
		if (0 > resting)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
			result = max;
		}
	}
	cout << result;
}