#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int>> timeMap;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		if (A <= B) 
			timeMap.emplace_back(A, B);
	}

	sort(timeMap.begin(), timeMap.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
		});

	int cnt = 0;
	int lastTime = 0;
	for (const auto& iter : timeMap)
	{
		if (lastTime <= iter.first)
		{
			lastTime = iter.second;
			++cnt;
		}
	}
	cout << cnt;
}