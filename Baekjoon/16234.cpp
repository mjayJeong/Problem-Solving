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

    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> grid(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int days = 0;

    while (true) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        bool moved = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                
                queue<pair<int, int>> q;
                vector<pair<int, int>> unionCells;
                int sum = 0;

                q.push({i, j});
                visited[i][j] = true;
                unionCells.push_back({i, j});
                sum += grid[i][j];

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (visited[nx][ny]) continue;

                        int diff = abs(grid[x][y] - grid[nx][ny]);
                        if (diff >= L && diff <= R) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            unionCells.push_back({nx, ny});
                            sum += grid[nx][ny];
                        }
                    }
                }

                if (unionCells.size() >= 2) {
                    moved = true;
                    int avg = sum / unionCells.size();
                    for (auto [x, y] : unionCells) {
                        grid[x][y] = avg;
                    }
                }
            }
        }

        if (!moved) break;
        days++;
    }

    cout << days << '\n';
    return 0;
}
