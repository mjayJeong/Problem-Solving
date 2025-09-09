#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  

    vector<vector<int>> grid(n, vector<int>(m));  // 2차원 배열 선언
    pair<int, int> target = {1, -1};  // 시작 지점 찾기

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) target = {i, j};
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));  // 거리 배열 : 기본적으로 -1로 채움 (visited 대용)

    // 0인 부분들 0으로 채우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;  
    q.push(target);
    dist[target.first][target.second] = 0;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

            if (grid[nr][nc] == 1 && dist[nr][nc] == -1) {   // 갈 수 있는 땅인데 방문 안했으면
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}
