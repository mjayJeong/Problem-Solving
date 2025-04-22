// BFS 풀이

import java.util.*;

class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[amount + 1];

        queue.offer(0);
        visited[0] = true;

        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;

            for (int i = 0; i < size; i++) {
                int current = queue.poll();

                for (int coin : coins) {
                    int next = current + coin;
                    if (next == amount) return level;

                    if (next < amount + 1 && !visited[next]) {
                        visited[next] = true;
                        queue.offer(next);
                    }
                }
            }
        }
        return -1;
    }
}

// Dynamice Programming 풀이

// class Solution {
//     public int coinChange(int[] coins, int amount) {
//         int max = amount + 1;
//         int[] dp = new int[amount+1];
//         Arrays.fill(dp, max);
//         dp[0] = 0;

//         for (int i = 1; i <= amount; i++) {
//             for (int coin : coins) {
//                 if (i - coin >= 0) {
//                     dp[i] = Math.min(dp[i], dp[i-coin] + 1);
//                 }
//             }
//         }
//         return dp[amount] == max ? -1 : dp[amount];
//     }
// }
