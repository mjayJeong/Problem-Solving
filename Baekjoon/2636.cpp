#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int time = 0;
    int last = 0; 

    while (true) {
        // 1. 현재 치즈 개수 세기
        int cheese = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) cheese++;
            }
        }
        if (cheese == 0) break;     // 치즈 남아있지 않으면 중단
        last = cheese;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> melt;

        q.push({0, 0});
        visited[0][0] = true;

        // 외부 공기 BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;

                if (grid[nx][ny] == 0) {
                    q.push({nx, ny});
                } 
                else if (grid[nx][ny] == 1) {
                    melt.push_back({nx, ny});
                }
            }
        }
        for (auto [x, y] : melt) {
            grid[x][y] = 0;
        }
        time++;
    }
    cout << time << '\n' << last << '\n';

    return 0;
}
