#include <iostream>

using namespace std;

int arr[101][101];
int brr[101][101];
int ress[101][101];

int main()
{
	int N, M, K = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> brr[i][j];
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int k = 0; k < K; k++)
		{
			for (int m = 0; m < M; m++)
			{
				ress[n][k] += arr[n][m] * brr[m][k];
			}
			cout << ress[n][k] << " ";
		}
		cout << endl;
	}
	return 0;
}