class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // i, j를 정사각형 오른쪽 아래 꼭짓점이라고 할 때 만들 수 있는 가장 큰 정사각형 길이 
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // 초기값 세팅
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') dp[i][0] = 1;
            else dp[i][0] = 0;
        }

        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == '1') dp[0][i] = 1;
            else dp[0][i] = 0; 
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    if (dp[i-1][j] == 0 || dp[i-1][j-1] == 0 || dp[i][j-1] == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, dp[i][j]);
            }
        }

        // 넓이 반환이니깐 길이 x 길이
        return answer * answer;
    }
};

// i, j를 정사각형 오른쪽 아래 꼭짓점이라고 할 때 만들 수 있는 가장 큰 정사각형 길이 
// dp[i][j] == 1 -> 1
// 젤 왼쪽, 위 라인은 다 0, 1로 채워놓기 
