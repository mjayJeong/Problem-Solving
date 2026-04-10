#include <string>

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int N, M;

    vector<vector<bool>> visited;

    // 주변 지뢰 개수 탐색
    int check_mine(int x, int y, vector<vector<char>>& board) {
        int cnt = 0; 

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[nx][ny] == 'M') cnt++;
        }
        return cnt;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        if (board[x][y] == 'E') {
            int num = check_mine(x, y, board);
            if (num > 0) {
                board[x][y] = num + '0';
            } else {
                board[x][y] = 'B';
                visited[x][y] = true;
                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (!visited[nx][ny] && board[nx][ny] == 'E') {
                        visited[nx][ny] = true;
                        dfs(nx, ny, board);
                    }
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        N = board.size();
        M = board[0].size();

        visited.assign(N, vector<bool>(M, false));
        visited[click[0]][click[1]] = true;
        dfs(click[0], click[1], board);

        return board;
    }
};

// 'M' 누르면 -> 바로 'X'로 변환
// 'E' 누르면 -> 주변 지뢰 개수 탐색 -> 개수에 따라서 숫자로 변환 
//                                     지뢰 없으면 'B'로 바꾸고 주변 8칸 탐색 
