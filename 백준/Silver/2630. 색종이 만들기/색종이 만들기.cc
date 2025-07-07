#include <iostream>
#include <vector>
using namespace std;

int blue = 0, white = 0;

// 주어진 구역이 모두 같은 색인지 확인하는 함수
bool isUniform(const vector<vector<int>> &paper, int x, int y, int size) {
    int color = paper[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

// 재귀적으로 종이를 분할하며 색종이의 개수를 세는 함수
void divide(const vector<vector<int>> &paper, int x, int y, int size) {
    // 현재 구역의 모든 색이 같으면 해당 색의 카운트를 증가시킨다.
    if (isUniform(paper, x, y, size)) {
        if (paper[x][y] == 0)
            white++;
        else
            blue++;
        return;
    }
    
    // 그렇지 않으면 사분면으로 나누어 다시 재귀호출한다.
    int half = size / 2;
    divide(paper, x, y, half);              // 왼쪽 위
    divide(paper, x, y + half, half);         // 오른쪽 위
    divide(paper, x + half, y, half);         // 왼쪽 아래
    divide(paper, x + half, y + half, half);    // 오른쪽 아래
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> paper(n, vector<int>(n));
    
    // 종이 정보 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    
    // 재귀 호출 시작 (전체 종이에서 시작)
    divide(paper, 0, 0, n);
    
    cout << white << "\n" << blue << "\n";
    return 0;
}