// DFS 풀이

class Solution {
    static boolean[][] visited;
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};

    public int numIslands(char[][] grid) {
        int cnt = 0;
        visited = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void dfs(int x, int y, char[][] map) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nowX = x + dx[i];
            int nowY = y + dy[i];

            if (nowX >= 0 && nowY >= 0 && nowX < map.length && nowY < map[0].length) {
                if (map[nowX][nowY] == '1' && !visited[nowX][nowY]) {
                    dfs(nowX, nowY, map);
                }
            }
        }
    }
}
