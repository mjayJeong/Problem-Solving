#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int map[51][51];
bool visited[51][51];
int n, L, R;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int start_x, int start_y) {
    queue<pair<int,int>> q;
    vector<pair<int,int>> coords;
    int total = 0;

    q.push({start_x, start_y});
    coords.push_back({start_x, start_y});
    total += map[start_x][start_y];
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        auto [x,y] = q.front(); 
        q.pop();

        for (int i = 0;i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                int diff = abs(map[x][y] - map[nx][ny]);
                if (diff >= L && diff <= R) {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                    coords.push_back({nx,ny});
                    total += map[nx][ny];
                }
            }
        }
    }
    // 연합이 생겼으면 평균값으로
    if (coords.size() > 1) {
        int new_val = total / coords.size();
        for (auto [x,y] : coords) {
            map[x][y] = new_val;
        }
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        bool moved = false;
        for (int i = 0; i < n ;i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (bfs(i,j)) moved = true;
                }
            }
        }
        if (!moved) break; // 연합 없으면 종료
        answer++;
    }
    cout << answer << '\n';
    return 0;
}
