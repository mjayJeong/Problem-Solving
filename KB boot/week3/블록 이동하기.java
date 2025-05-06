import java.util.*;

class Solution {
    static class Position {
        int x1, y1, x2, y2, time;

        Position(int x1, int y1, int x2, int y2, int time) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.time = time;
        }
    }

    public int solution(int[][] board) {
        int n = board.length;
        boolean[][][][] visited = new boolean[n][n][n][n];
        Queue<Position> queue = new LinkedList<>();

        queue.offer(new Position(0, 0, 0, 1, 0));
        visited[0][0][0][1] = true;

        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!queue.isEmpty()) {
            Position curr = queue.poll();

            int x1 = curr.x1, y1 = curr.y1, x2 = curr.x2, y2 = curr.y2;

            if ((x1 == n - 1 && y1 == n - 1) || (x2 == n - 1 && y2 == n - 1)) {
                return curr.time;
            }

            // 네 방향 이동
            for (int[] d : dirs) {
                int nx1 = x1 + d[0], ny1 = y1 + d[1];
                int nx2 = x2 + d[0], ny2 = y2 + d[1];

                if (isValid(nx1, ny1, n, board) && isValid(nx2, ny2, n, board)) {
                    if (!visited[nx1][ny1][nx2][ny2]) {
                        visited[nx1][ny1][nx2][ny2] = true;
                        queue.offer(new Position(nx1, ny1, nx2, ny2, curr.time + 1));
                    }
                }
            }

            // 회전
            if (x1 == x2) { // 가로 상태
                for (int d : new int[]{-1, 1}) {
                    if (isValid(x1 + d, y1, n, board) && isValid(x2 + d, y2, n, board)) {
                        if (!visited[x1][y1][x1 + d][y1]) {
                            visited[x1][y1][x1 + d][y1] = true;
                            queue.offer(new Position(x1, y1, x1 + d, y1, curr.time + 1));
                        }
                        if (!visited[x2][y2][x2 + d][y2]) {
                            visited[x2][y2][x2 + d][y2] = true;
                            queue.offer(new Position(x2, y2, x2 + d, y2, curr.time + 1));
                        }
                    }
                }
            } else { // 세로 상태
                for (int d : new int[]{-1, 1}) {
                    if (isValid(x1, y1 + d, n, board) && isValid(x2, y2 + d, n, board)) {
                        if (!visited[x1][y1][x1][y1 + d]) {
                            visited[x1][y1][x1][y1 + d] = true;
                            queue.offer(new Position(x1, y1, x1, y1 + d, curr.time + 1));
                        }
                        if (!visited[x2][y2][x2][y2 + d]) {
                            visited[x2][y2][x2][y2 + d] = true;
                            queue.offer(new Position(x2, y2, x2, y2 + d, curr.time + 1));
                        }
                    }
                }
            }
        }

        return 0;
    }

    private boolean isValid(int x, int y, int n, int[][] board) {
        return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0;
    }
}
