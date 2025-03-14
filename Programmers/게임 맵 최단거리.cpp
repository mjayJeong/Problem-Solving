#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<int>> maps, int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    visited[0][0] = 1; 
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return visited[x][y];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1; 
                q.push({nx, ny});
            }
        }
    }

    return -1; 
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    return bfs(maps, n, m);
}
