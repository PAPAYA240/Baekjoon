#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> resultCard;
	vector<int> myCard;
	vector<int> ansVec;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		resultCard.push_back(input);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input = 0;
		cin >> input;
		myCard.push_back(input);
	}

	sort(resultCard.begin(), resultCard.end());

	for (int i = 0; i < M; i++)
	{
		long long start = 0;
		long long end = N;
		while (start <= end)
		{
			long long mid = (start + end) / 2;
			if (resultCard[mid] == myCard[i])
			{
				ansVec.push_back(1);
				start = end + 1;
			}
			else if (resultCard[mid] < myCard[i])
			{
				start = mid + 1;
				if (start >= resultCard.size())
					break;
			}
			else
			{
				end = mid - 1;
			}
		}

		if (i != ansVec.size() - 1)
			ansVec.push_back(0);
	}

	for (int i = 0; i < ansVec.size(); i++)
		cout << ansVec[i] << ' ';
}