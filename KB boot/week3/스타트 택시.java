import java.util.*;

class Main {
    static class Passenger {
        int sx, sy, ex, ey;
        Passenger(int sx, int sy, int ex, int ey) {
            this.sx = sx; this.sy = sy; this.ex = ex; this.ey = ey;
        }
    }

    static int N, M, fuel;
    static int[][] map;
    static int taxiX, taxiY;
    static List<Passenger> passengers = new ArrayList<>();
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt(); fuel = sc.nextInt();
        map = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                map[i][j] = sc.nextInt();

        taxiX = sc.nextInt() - 1;
        taxiY = sc.nextInt() - 1;

        for (int i = 0; i < M; i++) {
            int sx = sc.nextInt() - 1;
            int sy = sc.nextInt() - 1;
            int ex = sc.nextInt() - 1;
            int ey = sc.nextInt() - 1;
            passengers.add(new Passenger(sx, sy, ex, ey));
        }

        for (int i = 0; i < M; i++) {
            int[] target = findClosestPassenger();
            if (target == null || target[2] > fuel) {
                System.out.println(-1);
                return;
            }
            taxiX = target[0]; taxiY = target[1];
            fuel -= target[2];
            Passenger p = passengers.remove(target[3]);

            int distToDest = bfs(taxiX, taxiY, p.ex, p.ey);
            if (distToDest == -1 || distToDest > fuel) {
                System.out.println(-1);
                return;
            }
            fuel += distToDest;
            taxiX = p.ex; taxiY = p.ey;
        }
        System.out.println(fuel);
    }

    static int[] findClosestPassenger() {
        boolean[][] visited = new boolean[N][N];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{taxiX, taxiY, 0});
        visited[taxiX][taxiY] = true;
        List<int[]> candidates = new ArrayList<>();
        int minDist = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0], y = curr[1], dist = curr[2];
            if (dist > minDist) break;
            for (int i = 0; i < passengers.size(); i++) {
                Passenger p = passengers.get(i);
                if (x == p.sx && y == p.sy) {
                    candidates.add(new int[]{x, y, dist, i});
                    minDist = dist;
                }
            }
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && map[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny, dist + 1});
                }
            }
        }
        if (candidates.isEmpty()) return null;
        candidates.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        return candidates.get(0);
    }

    static int bfs(int sx, int sy, int ex, int ey) {
        boolean[][] visited = new boolean[N][N];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{sx, sy, 0});
        visited[sx][sy] = true;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0], y = curr[1], dist = curr[2];
            if (x == ex && y == ey) return dist;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && map[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny, dist + 1});
                }
            }
        }
        return -1;
    }
}
