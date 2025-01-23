#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N = 0, Attack = 0;
	cin >> N >> Attack;

	vector<tuple<int, int, int>> vec;
	long long result = 9e18;
	for (int i = 0; i < N; i++)
	{
		int t, a, h;
		cin >> t >> a >> h;
		vec.push_back({ t, a, h });
	}

	long long start = 1, end = 9e18;
	while (start <= end)
	{
		long long MaxHp = (start + end) / 2;
		long long CurrentHp = MaxHp;
		long long playerAttack = Attack;
		bool bDead = false;
		for (const auto& iter : vec)
		{
			// 관문 1
			if (1 == get<0>(iter))
			{
				long long monsterHp = get<2>(iter);
				long long monsterAttack = get<1>(iter);
				bool bPlayerAttack = true;

				long long hitPlayerCnt = ceil((double)monsterHp / playerAttack); 
				long long hitMonsterCnt = ceil((double)CurrentHp / monsterAttack);

				if (hitPlayerCnt <= hitMonsterCnt) 
				{
					CurrentHp -= (hitPlayerCnt - 1) * monsterAttack;
				}
				else 
				{ 
					bDead = true;
					break;
				}
			}
			// 관문 2
			else
			{
				playerAttack += get<1>(iter);
				CurrentHp += get<2>(iter);

				if (CurrentHp > MaxHp)
					CurrentHp = MaxHp;
			}
		}

		if (!bDead)
		{
			end = MaxHp - 1;
			result = min(result, MaxHp);
		}
		else
			start = MaxHp + 1;
	}
	cout << result;
}
