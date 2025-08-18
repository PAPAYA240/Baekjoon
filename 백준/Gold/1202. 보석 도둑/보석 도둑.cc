#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n, k, c;

	auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second < b.second;
		};

	cin >> n >> k;
	vector<pair<int, int>> jewls(n);
	pair<int, int> a;
	for (int i = 0; i < n; i++)
	{
		cin >> a.first >> a.second;
		jewls[i] = a;
	}

	vector<int> bags(k);
	for (int i = 0; i < k; i++)
		cin >> bags[i];

	sort(jewls.begin(), jewls.end());
	sort(bags.begin(), bags.end());

	priority_queue<int> pq;
	long long result = 0;
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		while (idx < n && jewls[idx].first <= bags[i])
		{
			pq.push(jewls[idx].second);
			++idx;
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}