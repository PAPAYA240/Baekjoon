#include<iostream>
#include<string>

using namespace std;
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
	fastio();

	int n;
	int state = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		string str;
		cin >> str;

		if (str == "add")
		{
			cin >> x;
			state |= (1 << (x - 1));
		}
		else if (str == "remove")
		{
			cin >> x;
			state &= (~(1 << (x - 1)));
		}
		else if (str == "check")
		{
			cin >> x;
			cout << ((state >> (x - 1)) & 1) << '\n';
		}
		else if (str == "toggle")
		{
			cin >> x;
			state ^= (1 << (x - 1));
		}
		else if (str == "all")
		{
			state = 0xfffff;
		}
		else
		{
			state = 0;
		}
	}
}