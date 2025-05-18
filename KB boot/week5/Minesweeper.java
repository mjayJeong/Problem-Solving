class Solution {
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    public char[][] updateBoard(char[][] board, int[] click) {
        int row = click[0];
        int col = click[1];

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            dfs(board, row, col);
        }
        return board;
    }

    private void dfs(char[][] board, int x, int y) {
        int m = board.length, n = board[0].length;

        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E') {
            return;
        }

        int mineCount = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                mineCount++;
            }
        }

        if (mineCount > 0) {
            board[x][y] = (char)(mineCount + '0');
        } else {
            board[x][y] = 'B';

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                dfs(board, nx, ny);
            }
        }
    }
}
