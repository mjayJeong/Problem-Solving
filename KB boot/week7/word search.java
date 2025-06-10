class Solution {
    public boolean exist(char[][] board, String word) {
        int rows = board.length, cols = board[0].length;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int idx, int x, int y) {
        if (idx == word.length()) return true;

        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length 
            || board[x][y] != word.charAt(idx)) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '#'; 

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            if (dfs(board, word, idx + 1, x + dx[d], y + dy[d])) {
                return true;
            }
        }

        board[x][y] = temp; 
        return false;
    }
}
