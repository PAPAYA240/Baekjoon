#include<iostream>

using namespace std;

int myData[500001] = {};
int myTemp[500001] = {};
int n, m;
int saveNum = 0;
int saveSec = 0;

void Save(int _num)
{
	((++saveSec) == m) ? (saveNum = _num) :0;
}
void Divide(int l, int r)
{
	if (l == r)
		return;

	// # 분할
	int mid = (l + r) * 0.5f;
	Divide(l, mid);
	Divide(mid + 1, r);

	// # 정복
	int p1 = l;
	int p2 = mid + 1;
	int p3 = l;

	while (p1 <= mid && p2 <= r)
	{
		if (myData[p1] > myData[p2])
		{
			Save(myData[p2]);
			myTemp[p3++] = myData[p2++];
		}
		else
		{
			Save(myData[p1]);
			myTemp[p3++] = myData[p1++];
		}
	}

	while (p1 <= mid)
	{
		Save(myData[p1]);
		myTemp[p3++] = myData[p1++];
	}

	while(p2 <= r)
	{
		Save(myData[p2]);
		myTemp[p3++] = myData[p2++];
	}

	for(int i = l ; i <= r ; i++)
		myData[i] = myTemp[i];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> myData[i];

	Divide(0, n -1);

	if (saveSec < m)
		cout << "-1" << endl;
	else
		cout << saveNum << endl;
}