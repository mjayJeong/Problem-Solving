class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.size();
        int N = text2.size();

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (text1[j-1] != text2[i-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        return dp[N][M];
    }
};
