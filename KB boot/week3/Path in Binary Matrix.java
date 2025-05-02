// BFS 풀이

import java.util.*;

class Solution {
    static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;

        // 시작점이나 끝점이 막혀있으면 바로 -1
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        return bfs(grid, n);
    }

    public int bfs(int[][] grid, int n) {
        int[][] visited = new int[n][n];
        Queue<int[]> queue = new LinkedList<>();

        visited[0][0] = 1;
        queue.offer(new int[]{0, 0});

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1];

            if (x == n - 1 && y == n - 1) {
                return visited[x][y];
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n 
                    && grid[nx][ny] == 0 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }

        return -1;
    }
}
