import java.util.*;

class Solution {
    static class Edge{
        int to, distance;
        
        Edge(int to, int distance) {
            this.to = to;
            this.distance = distance;
        }
    }
    
    static class Entry implements Comparable<Entry> {
        int node, distance;
        
        Entry(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }
        
        @Override
        public int compareTo(Entry o) {
            return this.distance - o.distance;
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        
        Map<Integer, List<Edge>> graph = new HashMap<>();
        for (int[] r : road) {
            graph.computeIfAbsent(r[0], x -> new ArrayList<>()).add(new Edge(r[1], r[2]));
            graph.computeIfAbsent(r[1], x -> new ArrayList<>()).add(new Edge(r[0], r[2]));  // 양방향
        }
        
        int[] distance = new int[N + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[1] = 0;
        
        PriorityQueue<Entry> pq = new PriorityQueue<>();
        pq.offer(new Entry(1, 0));
        
        while (!pq.isEmpty()) {
            Entry curr = pq.poll();
            
            if (!graph.containsKey(curr.node)) continue;
            
            for (Edge edge : graph.get(curr.node)) {
                int newDistance = curr.distance + edge.distance;
                if (newDistance < distance[edge.to]) {
                    distance[edge.to] = newDistance;
                    pq.offer(new Entry(edge.to, newDistance));
                }
            }
        }
        
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (distance[i] <= K) cnt++;
        }

        return cnt;
    }
}
