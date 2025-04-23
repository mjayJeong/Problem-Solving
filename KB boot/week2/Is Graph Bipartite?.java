class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];   // 0 : 미방문, 1 : 빨강, -1 : 파랑

        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                color[i] = 1;

                while (!q.isEmpty()) {
                    int curr = q.poll();
                    for (int next : graph[curr]) {
                        if (color[next] == 0) {
                            color[next] = -color[curr];
                            q.add(next);
                        } else if (color[next] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
