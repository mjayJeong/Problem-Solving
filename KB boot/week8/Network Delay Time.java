import java.util.*;

class Solution {
    static class Edge {
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

    public int networkDelayTime(int[][] times, int n, int k) {
        
        Map<Integer, List<Edge>> graph = new HashMap<>();
        for (int[] time : times) {
            graph.computeIfAbsent(time[0], x -> new ArrayList<>()).add(new Edge(time[1], time[2]));
        }

        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        PriorityQueue<Entry> pq = new PriorityQueue<>();
        pq.offer(new Entry(k, 0));

        while (!pq.isEmpty()) {
            Entry curr = pq.poll();
            if (!graph.containsKey(curr.node)) continue;

            for (Edge edge : graph.get(curr.node)) {
                int newDist = curr.distance + edge.distance;
                if (newDist < dist[edge.to]) {
                    dist[edge.to] = newDist;
                    pq.offer(new Entry(edge.to, newDist));
                }
            }
        }

        int max = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            max = Math.max(max, dist[i]);
        }

        return max;
    }
}
