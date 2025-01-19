#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int N, M;
map<int, int> Card;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int input;
	for (int i = 0; i < N; i++)
	{

		cin >> input;
		++Card[input];
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		cout << Card[input] << ' ';
	}
}