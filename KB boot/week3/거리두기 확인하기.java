// BFS 풀이

import java.util.*;

class Solution {
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        
        for (int i = 0; i < 5; i++) {
            if (checkRoom(places[i])) {
                answer[i] = 1;
            } else {
                answer[i] = 0;
            }
        }
        
        return answer;
    }
    
    private boolean checkRoom(String[] room) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (room[i].charAt(j) == 'P') {
                    if (!bfs(room, i, j)) return false;
                }
            }
        }
        return true;
    }
    
    private boolean bfs(String[] room, int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y, 0});
        boolean[][] visited = new boolean[5][5];
        visited[x][y] = true;
        
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int cx = cur[0];
            int cy = cur[1];
            int dist = cur[2];
            
            if (dist >= 2) continue;
            
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    char next = room[nx].charAt(ny);
                    if (next == 'P') return false;
                    if (next == 'O') queue.offer(new int[]{nx, ny, dist + 1});
                }
            }
        }
        return true;
    }
}
