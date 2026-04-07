#include <vector>
#include <string>

class Solution {
public:
    int n;
    int m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<bool>> visited;
    bool answer = false;

    void dfs(int x, int y, vector<vector<char>>& board, string cur, string word) {
        if (cur == word) {
            answer = true;
            return;
        }

        if (cur.size() >= word.size()) return;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny, board, cur + board[nx][ny], word);
                visited[nx][ny] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        vector<pair<int, int>> location;        // 첫 단어 위치 저장 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    location.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < location.size(); i++) {
            visited.assign(n, vector<bool>(m, false));
            int x = location[i].first;
            int y = location[i].second;
            visited[x][y] = true;
            dfs(x, y, board, string(1, word[0]), word);
        }

        return answer;
    }
};
