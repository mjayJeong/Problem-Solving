import java.util.*;

class Solution {
    static int[] dx = {0, 0, -1, 1}; 
    static int[] dy = {-1, 1, 0, 0};

    public int solution(int n, int m, int[][] hole) {
        boolean[][][] visited = new boolean[n + 1][m + 1][2]; 
        boolean[][] isHole = new boolean[n + 1][m + 1];

        for (int[] h : hole) {
            isHole[h[0]][h[1]] = true;
        }

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 1, 0, 0}); // x, y, 신발사용여부, 시간
        visited[1][1][0] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], used = cur[2], time = cur[3];

            if (x == n && y == m) return time;

            // 1칸 걷기
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !isHole[nx][ny] && !visited[nx][ny][used]) {
                    visited[nx][ny][used] = true;
                    queue.offer(new int[]{nx, ny, used, time + 1});
                }
            }

            // 2칸 점프 (신발 사용 X)
            if (used == 0) {
                for (int i = 0; i < 4; i++) {
                    int nx = x + 2 * dx[i];
                    int ny = y + 2 * dy[i];

                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !isHole[nx][ny] && !visited[nx][ny][1]) {
                        visited[nx][ny][1] = true;
                        queue.offer(new int[]{nx, ny, 1, time + 1});
                    }
                }
            }

        }

        return -1;
    }
}
