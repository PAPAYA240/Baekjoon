#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	vector<int> vecLengh;

	long long Sum = 0;
	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		vecLengh.push_back(input);
		Sum += input;
	}

	long long start = 1;
	long long end = Sum;
	long long result = 0;

	while (start <= end)
	{
		long long cnt = 0;
		long long middle = (start + end) / 2;

		for (int i = 0; i < N; i++)
			cnt += vecLengh[i] / middle;
		
		// 보다 많으면
		if (K <= cnt)
		{
			start = middle + 1;
			result = middle;
		}
		else if (K > cnt)
		{
			end = middle - 1;
		}
	}


	cout << result;
}