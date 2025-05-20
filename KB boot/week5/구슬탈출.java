import java.util.*;

class Position {
    int rx, ry, bx, by;

    Position(int rx, int ry, int bx, int by) {
        this.rx = rx;
        this.ry = ry;
        this.bx = bx;
        this.by = by;
    }
}

public class Main {
    static int N, M;
    static char[][] board;
    static boolean[][][][] visited;
    static int[] dx = {-1, 1, 0, 0}; 
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        board = new char[N][M];
        int rx = 0, ry = 0, bx = 0, by = 0;

        for (int i = 0; i < N; i++) {
            String row = sc.next();
            for (int j = 0; j < M; j++) {
                board[i][j] = row.charAt(j);
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                } else if (board[i][j] == 'B') {
                    bx = i;
                    by = j;
                }
            }
        }

        System.out.println(bfs(rx, ry, bx, by));
    }

    static int bfs(int rx, int ry, int bx, int by) {
        Queue<Position> queue = new LinkedList<>();
        visited = new boolean[N][M][N][M];
        visited[rx][ry][bx][by] = true;
        queue.add(new Position(rx, ry, bx, by));
        int time = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int s = 0; s < size; s++) {
                Position p = queue.poll();

                for (int dir = 0; dir < 4; dir++) {
                    MoveResult red = move(p.rx, p.ry, dir);
                    MoveResult blue = move(p.bx, p.by, dir);

                    if (board[blue.x][blue.y] == 'O') continue;
                    if (board[red.x][red.y] == 'O') return 1;

                    if (red.x == blue.x && red.y == blue.y) {
                        if (red.dist > blue.dist) {
                            red.x -= dx[dir];
                            red.y -= dy[dir];
                        } else {
                            blue.x -= dx[dir];
                            blue.y -= dy[dir];
                        }
                    }

                    if (!visited[red.x][red.y][blue.x][blue.y]) {
                        visited[red.x][red.y][blue.x][blue.y] = true;
                        queue.add(new Position(red.x, red.y, blue.x, blue.y));
                    }
                }
            }

            if (++time > 10) return 0;
        }

        return 0;
    }

    static class MoveResult {
        int x, y, dist;

        MoveResult(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }

    static MoveResult move(int x, int y, int dir) {
        int dist = 0;
        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (board[nx][ny] == '#') break;
            x = nx;
            y = ny;
            dist++;
            if (board[x][y] == 'O') break;
        }
        return new MoveResult(x, y, dist);
    }
}
