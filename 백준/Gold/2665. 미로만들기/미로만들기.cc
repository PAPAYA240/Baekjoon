#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N = 0;
const int MAX_N = 52;

vector<vector<int>> InputVec(MAX_N, vector<int>(MAX_N));
vector<vector<int>> L(MAX_N, vector<int>(MAX_N, 99));

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void input() 
{
    cin >> N;
    for (int i = 0; i < N; ++i) 
    {
        string str;
        cin >> str;

        for (int j = 0; j < N; ++j) 
        {
            InputVec[i][j] = (str[j] - '0'); // 정수 변환 과정
        }
    }
}

void DFS(int x, int y, int level) 
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return;

    int leveling = level + abs(1 - InputVec[x][y]);

    if (L[x][y] <= leveling)
        return;
    
    L[x][y] = leveling;

    for (int i = 0; i < 4; ++i) {
        DFS(x + dx[i], y + dy[i], L[x][y]);
    }
}

int main() 
{
    input();

    DFS(0, 0, 0);

    cout << L[N - 1][N - 1] << endl;

    return 0;
}