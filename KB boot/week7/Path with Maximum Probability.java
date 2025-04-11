import java.util.*;

class Solution {
    static class Edge{
        int to;
        double prob;

        Edge(int to, double prob) {
            this.to = to;
            this.prob = prob;
        }
    }

    static class Entry implements Comparable<Entry> {
        int node;
        double prob;

        Entry(int node, double prob) {
            this.node = node;
            this.prob = prob;
        }
        
        @Override
        public int compareTo(Entry o) {
            return Double.compare(o.prob, this.prob);  // 큰 확률 우선 (내림차순)
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        
        Map<Integer, List<Edge>> graph = new HashMap<>();
        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0], b = edges[i][1];
            double prob = succProb[i];
            graph.computeIfAbsent(a, x -> new ArrayList<>()).add(new Edge(b, prob));
            graph.computeIfAbsent(b, x -> new ArrayList<>()).add(new Edge(a, prob));
        }

        double[] distance = new double[n];
        Arrays.fill(distance, 0.0);
        distance[start_node] = 1.0;

        PriorityQueue<Entry> pq = new PriorityQueue<>();
        pq.offer(new Entry(start_node, 1.0));

        while (!pq.isEmpty()) {
            Entry curr = pq.poll();

            if (curr.node == end_node) return curr.prob;

            if (!graph.containsKey(curr.node)) continue;

            for (Edge edge : graph.get(curr.node)) {
                double newProb = curr.prob * edge.prob;
                if (newProb > distance[edge.to]) {
                    distance[edge.to] = newProb;
                    pq.offer(new Entry(edge.to, newProb));
                }
            }
        }

        return 0.0;
    }
}
