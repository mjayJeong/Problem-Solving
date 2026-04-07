#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int super_dx[4] = {2, -2, 0, 0};
int super_dy[4] = {0, 0, 2, -2};

int solution(int n, int m, vector<vector<int>> hole) {
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < hole.size(); i++) {
        map[hole[i][0]][hole[i][1]] = 1;
    }

    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));
    queue<tuple<int, int, int>> q;

    q.push({1, 1, 0});           // x, y, 점프 사용 여부
    dist[1][1][0] = 0;

    while (!q.empty()) {
        auto [x, y, used] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (map[nx][ny] == 1) continue;
            if (dist[nx][ny][used] != -1) continue;

            dist[nx][ny][used] = dist[x][y][used] + 1;

            if (nx == n && ny == m) {
                return dist[nx][ny][used];
            }

            q.push({nx, ny, used});
        }

        if (used == 0) {
            for (int d = 0; d < 4; d++) {
                int nx = x + super_dx[d];
                int ny = y + super_dy[d];

                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (map[nx][ny] == 1) continue;
                if (dist[nx][ny][1] != -1) continue;

                dist[nx][ny][1] = dist[x][y][0] + 1;

                if (nx == n && ny == m) {
                    return dist[nx][ny][1];
                }

                q.push({nx, ny, 1});
            }
        }
    }

    return -1;
}
