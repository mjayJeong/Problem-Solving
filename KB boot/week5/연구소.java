import java.util.*;

public class Main
{
    static int n, m;
    static int[][] map;
    static int[][] temp;
    static int maxSafeZone = 0;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		map = new int[n][m];
		
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < m; j++) {
		        map[i][j] = sc.nextInt();
		    }
		}
		
		makeWall(0);
		System.out.println(maxSafeZone);
		
	}
	
	static void makeWall(int count) {
	    if (count == 3) {
	        spreadVirus();
	        return;
	    } 
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            if (map[i][j] == 0) {
	                map[i][j] = 1;
	                makeWall(count + 1);
	                map[i][j] = 0;
	            }
	        }
	    }
	}
	
	static void spreadVirus() {
	    temp = new int[n][m];
	    
	    // map 복제
	    for (int i = 0; i < n; i++) {
	        temp[i] = map[i].clone();
	    }
	    
	    Queue<int[]> queue = new LinkedList<>();
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            if (temp[i][j] == 2) {
	                queue.offer(new int[]{i, j});
	            }
	        }
	    }
	    
	    while (!queue.isEmpty()) {
	        int[] cur = queue.poll();
	        int x = cur[0];
	        int y = cur[1];
	        
	        for (int i = 0; i < 4; i++) {
	            int nx = x + dx[i];
	            int ny = y + dy[i];
	            
	            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
	                if (temp[nx][ny] == 0) {
	                    temp[nx][ny] = 2;
	                    queue.offer(new int[]{nx, ny});
	                }
	            }
	        }
	    }
	    countSafeZone();
	}
	
	static void countSafeZone() {
	    int cnt = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            if (temp[i][j] == 0) {
	                cnt++;
	            }
	        }
	    }
	    maxSafeZone = Math.max(maxSafeZone, cnt);
	}
}
