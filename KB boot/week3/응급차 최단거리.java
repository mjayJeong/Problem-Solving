import java.util.*;

class Solution {
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    public int solution(int[][] city) {
        int m = city.length;
        int n = city[0].length;

        return bfs(city, m, n);
    }

    public int bfs(int[][] city, int m, int n) {
        int[][] visited = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();

        if (city[0][0] == 1) return -1;

        visited[0][0] = 1;
        queue.offer(new int[]{0, 0});

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1];

            if (x == m - 1 && y == n - 1) {
                return visited[x][y];
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (city[nx][ny] == 0 && visited[nx][ny] == 0) {
                        visited[nx][ny] = visited[x][y] + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return -1; 
    }
}
