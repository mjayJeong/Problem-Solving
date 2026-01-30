#include <bits/stdc++.h>

using namespace std;

int M, N, K;
vector<vector<int>> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<bool>> visited;

vector<int> width;

void bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    visited[start_x][start_y] = true;
    q.push({start_x, start_y});
    int cnt = 1;        // 넓이 측정

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (!visited[nx][ny] && grid[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    width.push_back(cnt);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> K;
    grid.assign(M, vector<int>(N, 0));
    visited.assign(M, vector<bool>(N, false));

    for (int i = 0; i < K; i++) {
        int left_x, left_y, right_x, right_y;
        cin >> left_x >> left_y >> right_x >> right_y;

        // 지도에 먼저 사각형 부분 1로 표시 
        for (int y = left_y; y < right_y; y++) {
            for (int x = left_x; x < right_x; x++) {
                grid[y][x] = 1;
            }
        }
    }

    int answer = 0; 
    // bfs 돌면서 answer 개수 확인
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                bfs(i, j);
                answer++;
            }
        }
    }
    sort(width.begin(), width.end());

    cout << answer << "\n";
    for (int n : width) {
        cout << n << " ";
    }

    return 0;
}
