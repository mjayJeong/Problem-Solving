// BFS 풀이

import java.util.*;

class Solution {
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        return bfs(maps, n, m);
    }
    
    public int bfs(int[][] maps, int n, int m) {
        int[][] visited = new int[n][m];
        Queue<int[]> queue = new LinkedList<>();
        
        visited[0][0] = 1;
        queue.offer(new int[]{0, 0});
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0];
            int y = curr[1];
            
            if (x == n - 1 && y == m - 1) {
                return visited[x][y];
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                 if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                     visited[nx][ny] = visited[x][y] + 1;
                     queue.offer(new int[]{nx, ny});
                 }
            }
        }
        
        return -1;
    }
}
