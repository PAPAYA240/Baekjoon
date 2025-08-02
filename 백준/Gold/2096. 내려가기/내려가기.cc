#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1e9

using namespace std;

int n;
int moveIdx[3] = { -1, 0, 1 };

vector<vector<int>> v;
vector<long long> maxdp;
vector<long long> mindp;

void Result()
{
	long long result = 0;
	for (int i = 0; i < 3; i++)
	{
		result = max(result, maxdp[i]);
	}
	cout << result << " ";

	result = INF;
	for (int i = 0; i < 3; i++)
	{
		result = min(result, mindp[i]);
	}
	cout << result;
}

void Process()
{
	vector<long long> prevmax;
	vector<long long> prevmin;

	for (int i = 1; i < n; i++)
	{
		prevmax = maxdp;
		prevmin = mindp;
		for (int j = 0; j < 3; j++)
		{
			maxdp[j] = 0;
			mindp[j] = INF;
			for (int k = 0; k < 3; k++)
			{
				int prevIdx = j + moveIdx[k];
				if (prevIdx >= 3 || prevIdx < 0)
					continue;
				maxdp[j] = max(maxdp[j], v[j][i] + prevmax[prevIdx]);
				mindp[j] = min(mindp[j], v[j][i] + prevmin[prevIdx]);
			}
		}
	}
}

void Input()
{
	cin >> n;
	v.resize(3, vector<int>(n));

	mindp.resize(3, INF);
	maxdp.resize(3, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[j][i];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		maxdp[i] = v[i][0];
		mindp[i] = v[i][0];
	}
}

int main()
{
	Input();

	if (n <= 1)
	{
		Result();
		return 0;
	}

	Process();

	Result();
}