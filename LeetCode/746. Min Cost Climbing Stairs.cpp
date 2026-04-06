#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};

// dp[i] = i번째 계단에 도착했을 때의 최소 비용
// i-1에서 1칸 / i-2에서 2칸 올라오는 경우 
