import java.util.*;

class Solution {
    int max = 0;

    public int solution(int balance, int[][] countries) {
        boolean[] visited = new boolean[countries.length];
        dfs(balance, countries, 0, visited);
        return max;
    }

    private void dfs(int balance, int[][] countries, int count, boolean[] visited) {
        max = Math.max(max, count);

        for (int i = 0; i < countries.length; i++) {
            int cost = countries[i][0];     
            int required = countries[i][1]; 

            if (!visited[i] && balance >= required && balance >= cost) {
                visited[i] = true;
                dfs(balance - cost, countries, count + 1, visited);
                visited[i] = false;
            }
        }
    }
}
