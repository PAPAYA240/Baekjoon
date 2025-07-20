#include <stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int	n, m = 0;

int main()
{
	scanf("%d", &n);
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		vector<vector<int>> v(2, vector<int>(m));
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < m; k++)
				scanf("%d", &v[j][k]);

		v[0][1] = v[1][0] + v[0][1];
		v[1][1] = v[0][0] + v[1][1];

		for (int j = 2; j < m; j++)
		{
			v[0][j] += max(v[1][j - 1], v[1][j - 2]);
			v[1][j] += max(v[0][j - 1], v[0][j - 2]);
		}
		 
		int res = max(v[0][m-1], v[1][m-1]);
		result.emplace_back(res);
	}
	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);
}