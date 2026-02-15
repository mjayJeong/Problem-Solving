#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int l;
pair<int, int> arrive;

int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[8] = {-1, 1, -2, -2, -1, 1, 2, 2};

int bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(l, vector<int>(l, -1));

    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;   

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 도착지점이면 거리 반환
        if (x == arrive.first && y == arrive.second) {
            return dist[x][y];
        }
        
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    } 
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> l;
        pair<int, int> start;
        cin >> start.first >> start.second;
        cin >> arrive.first >> arrive.second;

        cout << bfs(start.first, start.second) << "\n";
    }

    return 0;
}
