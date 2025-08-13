#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

// 투 포인터 : 정렬된 배열에서만 사용 가능
// right left 활용
int main()
{
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int left = 0, right = n - 1;
	long long minResult = 4e9 + 1;
	pair<long long, long long> res;

	while (left < right)
	{
		long long sum = v[left] + v[right];
		if (minResult > abs(sum))
		{
			minResult = abs(sum);
			res.first = v[left];
			res.second = v[right];
		}

		if (sum > 0)
			right--;
		else if (sum < 0)
			left++;
		else
			break;
	}
	cout << res.first << " " << res.second;
}