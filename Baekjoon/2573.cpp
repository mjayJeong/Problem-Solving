#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void melting() {
    vector<vector<int>> melt(N, vector<int>(M, 0));

    // 녹는 양 계산 
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            if (map[i][j] <= 0) continue;

            int sea = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (map[nx][ny] == 0) sea++;
            }
            melt[i][j] = sea;
        }
    }

    // 녹이기
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            if (map[i][j] > 0) {
                map[i][j] = max(0, map[i][j] - melt[i][j]);
            }
        }
    }
}

int bfs() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int comp = 0;

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            if (map[i][j] > 0 && !visited[i][j]) {
                comp++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (!visited[nx][ny] && map[nx][ny] > 0) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return comp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 

    cin >> N >> M;
    map.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;
    while (true) {
        int answer = bfs();

        if (answer >= 2) {
            cout << year << '\n';
            break;
        }
        if (answer == 0) {
            cout << 0 << '\n';
            break;
        }

        melting();
        year++;
    }

    return 0;
}
