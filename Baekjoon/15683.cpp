#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> office;
vector<pair<int, pair<int,int>>> cctvs; 
int ans = 1e9;

int dx[4] = {-1, 0, 1, 0};  // 상, 우, 하, 좌 순서
int dy[4] = {0, 1, 0, -1};
 
// 한 방향으로 감시 표시
void watch(vector<vector<int>>& board, int x, int y, int dir) {
    int nx = x, ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
        if (board[nx][ny] == 6) break;                  // 벽이면 멈추기    
        if (board[nx][ny] == 0) board[nx][ny] = -1;     // 빈칸만 감시표시
    }
}

// 사각지대 개수 카운팅
int countBlind(const vector<vector<int>>& board) {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 0) cnt++;
    return cnt;
}

void dfs(int idx, vector<vector<int>> board) {
    if (idx == (int)cctvs.size()) {
        ans = min(ans, countBlind(board));
        return;
    }

    int type = cctvs[idx].first;
    int x = cctvs[idx].second.first;
    int y = cctvs[idx].second.second;

    if (type == 1) {             // 한 방향
        for (int d = 0; d < 4; d++) {
            auto tmp = board;
            watch(tmp, x, y, d);
            dfs(idx + 1, tmp);
        }
    } 
    else if (type == 2) {         // 양 방향
        for (int d = 0; d < 2; d++) {
            auto tmp = board;
            watch(tmp, x, y, d);
            watch(tmp, x, y, d + 2);
            dfs(idx + 1, tmp);
        }
    } 
    else if (type == 3) {          // 직각 방향
        for (int d = 0; d < 4; d++) {
            auto tmp = board;
            watch(tmp, x, y, d);
            watch(tmp, x, y, (d + 1) % 4);
            dfs(idx + 1, tmp);
        }
    } 
    else if (type == 4) {           // 세 방향
        for (int d = 0; d < 4; d++) {
            auto tmp = board;
            watch(tmp, x, y, d);
            watch(tmp, x, y, (d + 1) % 4);
            watch(tmp, x, y, (d + 2) % 4);
            dfs(idx + 1, tmp);
        }
    } 
    else if (type == 5) {           // 모든 방향
        auto tmp = board;
        for (int d = 0; d < 4; d++) watch(tmp, x, y, d);
        dfs(idx + 1, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    office.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctvs.push_back({office[i][j], {i, j}});
            }
        }
    }

    dfs(0, office);
    cout << ans << '\n';
    return 0;
}
