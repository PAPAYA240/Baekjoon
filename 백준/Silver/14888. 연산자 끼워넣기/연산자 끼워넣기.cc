#include<iostream>
#include<vector>

#define ADD 0 
#define SUBTRACT 1
#define MUTL 2
#define DIVISION 3

using namespace std;

int n;
vector<int> v;
int calc[4] = {};
pair<int, int> dp = { -2e9, 2e9 };

void Recur(int idx, int result, int myCalc[4])
{
	if (idx == n)
	{
		dp.first = max(result, dp.first);
		dp.second = min(result, dp.second);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (myCalc[i] <= 0)
			continue;

		--myCalc[i];
		if (i == ADD)
			Recur(idx + 1, result + v[idx], myCalc);
		else if (i == SUBTRACT)
			Recur(idx + 1, result - v[idx], myCalc);
		else if (i == MUTL)
			Recur(idx + 1, result * v[idx], myCalc);
		else
			Recur(idx + 1, result / v[idx], myCalc);
		++myCalc[i];
	}
}

int main()
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < 4; i++)
		cin >> calc[i];

	Recur(1, v[0], calc); 

	cout << dp.first << '\n' << dp.second;
}