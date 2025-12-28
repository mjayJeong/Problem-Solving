#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = 0;

// DFS로 4칸짜리 도형 만들기 (ㅗ 제외)
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

// ㅗ 모양(ㅜ,ㅓ,ㅏ,ㅗ) 체크
void checkT(int x, int y) {
    int center = board[x][y];

    // 4방향 중 3개를 더한 값이 ㅗ 모양
    for (int i = 0; i < 4; i++) {
        int sum = center;
        bool ok = true;

        for (int j = 0; j < 3; j++) {
            int dir = (i + j) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                ok = false;
                break;
            }
            sum += board[nx][ny];
        }

        if (ok) answer = max(answer, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 칸을 시작점으로 DFS + ㅗ 체크
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            checkT(i, j); // ㅗ 모양은 따로 처리
        }
    }

    cout << answer << "\n";
    return 0;
}
