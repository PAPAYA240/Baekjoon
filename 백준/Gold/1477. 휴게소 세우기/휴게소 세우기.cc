#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;

void ParamatricSerch(vector<int>& _vec)
{
	int start = 1;
	int end = L - 1;
	int result = 9999;

	while(start <= end)
	{
		int cnt = 0;
		int middle = (start + end) / 2;

		for (int i = 0; i < _vec.size() - 1; i++)
		{
			int dist = _vec[i + 1] - _vec[i];
			cnt += (dist / middle);
			if (0 == dist % middle)
				cnt -= 1;
		}

		if (cnt > M) // 설치할 게 더 많다면
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
			result = min(result, middle);
		}
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 현재 휴게소, 지으려는 휴게소, 고속도로 길이
	vector<int> RestingPos;
	cin >> N >> M >> L;

	RestingPos.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		RestingPos.emplace_back(input);
	}
	RestingPos.push_back(L);

	sort(RestingPos.begin(), RestingPos.end());
	ParamatricSerch(RestingPos);
}