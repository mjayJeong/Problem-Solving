#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int M, N, H;
vector<vector<vector<int>>> box;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;
    box.resize(H, vector<vector<int>>(N, vector<int>(M)));

    queue<tuple<int,int,int>> q; // z, y, x

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[h][i][j];
                if (box[h][i][j] == 1) {
                    q.push({h, i, j}); // 익은 토마토들 모두 시작점
                }
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        for (int d = 0; d < 6; d++) {
            int nz = z + dz[d];
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (box[nz][ny][nx] != 0) continue; // 0(안 익음)만 퍼뜨릴 수 있음

            box[nz][ny][nx] = box[z][y][x] + 1; // 날짜(거리) 기록
            q.push({nz, ny, nx});
        }
    }

    // 결과 계산
    int mx = 1;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[h][i][j] == 0) { // 끝까지 안 익은 토마토가 있으면
                    cout << -1 << "\n";
                    return 0;
                }
                mx = max(mx, box[h][i][j]);
            }
        }
    }

    // 처음부터 다 익어있으면 mx=1 -> 0일
    cout << (mx - 1) << "\n";
    return 0;
}
