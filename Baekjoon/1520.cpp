#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;   // 도착점

    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

        if (board[nx][ny] < board[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    board.assign(M, vector<int>(N));
    dp.assign(M, vector<int>(N, -1));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}
