class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, computers, visited, n);
                answer++;
            }
        }
            
        return answer;
    }
    
    private void dfs(int now, int[][] computers, boolean[] visited, int n) {
        visited[now] = true;
        for (int i = 0; i < n; i++) {
            if (computers[now][i] == 1 && !visited[i]) {
                dfs(i, computers, visited, n);
            }
        }
    }
}
