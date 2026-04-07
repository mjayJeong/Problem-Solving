#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        // 초기값 세팅
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// dp테이블 -> 각 지점에 올 수 있는 경우의 수 
// 미리 오른쪽 라인이랑 아래 라인은 다 1로 채워놓기 
// 위에서 오거나 / 오른쪽에서 오거나 (dp[i][j] = dp[i-1][j] + dp[i][j-1])
