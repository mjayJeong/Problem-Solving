#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int w, h;
char map[51][51];
bool visited[51][51];
int dist[51][51];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y)
{
    queue<pair<int, int>> q;

    int local_max = 0; 
    visited[x][y] = true;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[nx][ny] && map[nx][ny] == 'L') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                dist[nx][ny] = dist[now_x][now_y] + 1;
                
                if (dist[nx][ny] > local_max) local_max = dist[nx][ny];
            }
        } 
    }
    return local_max;
}

int main()
{
    cin >> w >> h;

    for (int i = 0; i < w; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < h; j++) {
            map[i][j] = line[j];
        }
    }

    int real_max = 0;

    // 모든 L 좌표에 대해서 bfs 돌리기
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (map[i][j] == 'L') {
                memset(visited, false, sizeof(visited));
                memset(dist, 0, sizeof(dist));
                real_max = max(real_max, bfs(i, j));
            }
        }
    }

    cout << real_max;

    return 0;
}
