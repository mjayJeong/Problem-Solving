#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    int grid[n][m];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int answer = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            answer = max(answer, grid[i][j]);
        }
    }
    cout << answer - 1;

    return 0;
}
