import java.util.*;

class Solution {
    int maxSheep = 0;
    Map<Integer, List<Integer>> graph = new HashMap<>();

    public int solution(int[] info, int[][] edges) {
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], x -> new ArrayList<>()).add(edge[1]);
        }

        List<Integer> nextNodes = new ArrayList<>();
        nextNodes.add(0);
        dfs(0, 0, 0, nextNodes, info);
        return maxSheep;
    }

    public void dfs(int current, int sheep, int wolf, List<Integer> nextNodes, int[] info) {
        if (info[current] == 0) sheep++;
        else wolf++;

        if (wolf >= sheep) return; 

        maxSheep = Math.max(maxSheep, sheep);

        List<Integer> newNext = new ArrayList<>(nextNodes);
        newNext.remove(Integer.valueOf(current));
        if (graph.containsKey(current)) newNext.addAll(graph.get(current));

        for (int next : newNext) {
            dfs(next, sheep, wolf, newNext, info);
        }
    }
}
