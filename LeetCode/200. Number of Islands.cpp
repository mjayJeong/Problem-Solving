class Solution {
public:
    int answer = 0; 
    int N, M;
    vector<vector<bool>> visited;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<char>>& grid) {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!visited[nx][ny] && grid[nx][ny] == '1') {
                visited[nx][ny] = true;
                dfs(nx, ny, grid);
            } 
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();

        visited.assign(N, vector<bool>(M, false));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j, grid);
                    answer++; 
                }
            }
        }

        return answer;
    }
};
