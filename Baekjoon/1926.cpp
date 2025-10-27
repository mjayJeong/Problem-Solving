#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[501][501];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int dfs(vector<vector<int>>& v, int start_x, int start_y)
{
    visited[start_x][start_y] = true;
    int area = 1;

    for (int i = 0; i < 4; i++) {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny] == 1) {
            area += dfs(v, nx, ny);
        }
    }
    return area;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int cnt = 0;        // 그림 개수
    int max_size = 0;   // 가장 넓은 그림 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1 && !visited[i][j]) {
                cnt++;
                int area = dfs(paper, i, j);
                max_size = max(max_size, area);
            }
        }
    }

    cout << cnt << '\n' << max_size << '\n';

    return 0;
}
