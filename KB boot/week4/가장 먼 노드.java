import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        
        // 1. 그래프 만들기
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edge) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        // 2. BFS 수행
        boolean[] visited = new boolean[n + 1];
        int[] distance = new int[n+1];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        visited[1] = true;
        
        while (!queue.isEmpty()) {
            int now = queue.poll();
            for (int next : graph.get(now)) {
                if (!visited[next]) {
                    visited[next] = true;
                    distance[next] = distance[now] + 1;
                    queue.add(next);
                }
            }
        }
        
        // 3. 가장 먼 거리 노드 개수 세기
        int max = 0;
        for (int d : distance) {
            if (d > max) max = d;
        }
        
        int answer = 0;
        for (int d : distance) {
            if (d == max) answer++;
        }
        
        return answer;
    }
}
