#include <iostream>

using namespace std;

int N = 0;
int result = 0;
int sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N != result)
	{
		int sub = 0;
		int C = 1;

		result = 0;
		++sum;
		if (80 == sum)
			int a = 0;
		sub = sum;

		while (true)
		{
			C *= 10;
			if (sub <= sub % C)
			{
				C = C / 10;
				break;
			}
		}

		while(C > 0)
		{
			result += (sub / C);
			sub %= C;
			C /= 10;
		}
		result += sum;

		if (result >= 1000000)
		{
			cout << "0";
			return 0;
		}
	}
	cout << sum;
}