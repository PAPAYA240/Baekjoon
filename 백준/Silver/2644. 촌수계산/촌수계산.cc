#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Relation {
    int parents;
    int child;
};

int N, M, A, B;
vector<Relation> RelationVec;
vector<int> kinship; // 각 사람의 촌수를 저장
queue<int> que;

void BFS() {
    que.push(A);
    kinship[A] = 0; // A의 촌수는 0으로 초기화

    while (!que.empty()) {
        int current = que.front();
        que.pop();

        for (const auto& rel : RelationVec) {
            if (rel.parents == current && kinship[rel.child] == -1) {
                kinship[rel.child] = kinship[current] + 1; // 촌수 증가
                que.push(rel.child);
            } else if (rel.child == current && kinship[rel.parents] == -1) {
                kinship[rel.parents] = kinship[current] + 1; // 촌수 증가
                que.push(rel.parents);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B >> M;

    // 촌수 배열 초기화
    kinship.resize(N + 1, -1); // -1로 초기화하여 방문 여부 체크

    // 관계 입력
    for (int i = 0; i < M; i++) {
        Relation rel;
        cin >> rel.parents >> rel.child;
        RelationVec.push_back(rel);
    }

    BFS();

    // B의 촌수 출력
    cout << kinship[B] << endl; 

    return 0;
}
