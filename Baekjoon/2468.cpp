#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

int n;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int depth) 
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] > depth) {
            dfs(nx, ny, depth);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (max_depth < map[i][j]) max_depth = map[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i <= max_depth; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!visited[j][k] && map[j][k] > i) {
                    dfs(j, k, i);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }

    cout << answer;

    return 0;
}
