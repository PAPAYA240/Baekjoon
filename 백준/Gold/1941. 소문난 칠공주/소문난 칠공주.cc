#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define S 2
#define Y 0

int MAP[5][5], Answer;
bool Select[25];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Input() {
    for (int i = 0; i < 5; i++) 
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); j++) {

            if (str[j] == 'Y')
                MAP[i][j] = Y;
            else
                MAP[i][j] = S;
        }
    }
}

bool MoreThanFour() 
{
    int Cnt = 0;
    for (int i = 0; i < 25; i++) 
    {
        if (Select[i]) 
        {
            int x = i / 5;
            int y = i % 5;
            if (MAP[x][y] == S)
                Cnt++;
        }
    }
    return Cnt >= 4; 
}

bool Adjacency() 
{
    queue<pair<int, int>> Q;

    bool Check_Select[5][5] = { false };
    bool Queue_Select[5][5] = { false };

    bool Check_Answer = false;
    memset(Queue_Select, false, sizeof(Queue_Select));
    memset(Check_Select, false, sizeof(Check_Select));

    for (int i = 0; i < 25; i++) 
    {
        if (Select[i]) 
        {
            int x = i / 5;
            int y = i % 5;

            Check_Select[x][y] = true;
            if (Q.empty()) 
            {
                Q.push(make_pair(x, y));
                Queue_Select[x][y] = true;
            }
        }
    }

    int Cnt = 1; // 시작점 카운트
    while (!Q.empty()) 
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        if (Cnt == 7) 
        {
            Check_Answer = true;
            break;
        }

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && Check_Select[nx][ny] && !Queue_Select[nx][ny])
            {
                Queue_Select[nx][ny] = true;
                Q.push(make_pair(nx, ny));
                Cnt++;
            }
        }
    }
    return Check_Answer;
}

void DFS(int Idx, int Cnt) 
{
    if (Cnt == 7) 
    {
        // 4명 이상이고 7명 학생이 인접한지 확인
        if (MoreThanFour() && Adjacency())
            Answer++;
        return;
    }
    for (int i = Idx; i < 25; i++) 
    {
        if (Select[i]) 
            continue;

        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    DFS(0, 0);

    cout << Answer << endl;

    return 0;
}