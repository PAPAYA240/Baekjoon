#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tomato {
	int y, x;
};

//상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int m, n;
int box[1001][1001];
queue<tomato> q;

void bfs(void) {

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m == 1 && box[ny][nx] == 0) {
				box[ny][nx] = box[y][x] + 1; 
				q.push({ ny, nx });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push({ i, j });
		}
	}

	bfs();

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (max < box[i][j]) max = box[i][j];
		}
	}

	cout << max - 1 << "\n";

	return 0;
}

