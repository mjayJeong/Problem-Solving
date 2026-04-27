#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<char>> board;
vector<vector<int>> devilTime;
vector<vector<int>> suyeonTime;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void devil_bfs(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (devilTime[nx][ny] != -1) continue;
            if (board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;

            devilTime[nx][ny] = devilTime[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int suyeon_bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    suyeonTime[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (board[x][y] == 'D') {
            return suyeonTime[x][y];
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (suyeonTime[nx][ny] != -1) continue;
            if (board[nx][ny] == 'X' || board[nx][ny] == '*') continue;

            int nextTime = suyeonTime[x][y] + 1;

            // 악마가 먼저 도착하거나 동시에 도착하면 이동 불가
            if (devilTime[nx][ny] != -1 && devilTime[nx][ny] <= nextTime) continue;

            suyeonTime[nx][ny] = nextTime;
            q.push({nx, ny});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;

        board.assign(N, vector<char>(M));
        devilTime.assign(N, vector<int>(M, -1));
        suyeonTime.assign(N, vector<int>(M, -1));

        queue<pair<int, int>> devilQ;
        pair<int, int> start;

        for (int i = 0; i < N; i++) {
            string line;
            cin >> line;

            for (int j = 0; j < M; j++) {
                board[i][j] = line[j];

                if (board[i][j] == '*') {
                    devilQ.push({i, j});
                    devilTime[i][j] = 0;
                }

                if (board[i][j] == 'S') {
                    start = {i, j};
                }
            }
        }

        devil_bfs(devilQ);

        int result = suyeon_bfs(start);

        cout << "#" << tc << " ";
        if (result == -1) {
            cout << "GAME OVER\n";
        } else {
            cout << result << '\n';
        }
    }

    return 0;
}
