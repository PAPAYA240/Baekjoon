#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 50 + 2;
int N;
vector<vector<int>> InputVec(MAX_N, vector<int>(MAX_N));
vector<vector<int>> L(MAX_N, vector<int>(MAX_N, 99));

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void input() 
{
    cin >> N;
    for (int i = 1; i <= N; ++i) 
    {
        string str;
        cin >> str;

        for (int j = 1; j <= N; ++j) 
        {
            InputVec[i][j] = 1 - (str[j - 1] - '0'); // 정수 변환 과정
        }
    }
}

void DFS(int x, int y, int level) 
{
    if (x < 1 || x > N || y < 1 || y > N)
        return;

    if (L[x][y] <= level + InputVec[x][y])
        return;

    L[x][y] = level + InputVec[x][y];

    for (int i = 0; i < 4; ++i) {
        DFS(x + dx[i], y + dy[i], L[x][y]);
    }
}

int main() 
{
    input();

    DFS(1, 1, 0);

    cout << L[N][N] << endl;

    return 0;
}