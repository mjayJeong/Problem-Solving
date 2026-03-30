#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> dist;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};

void bfs(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    graph.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    bfs(q);

    int answer = 0; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, dist[i][j]);
        }
    }

    cout << answer << '\n';
    
    return 0;
}
