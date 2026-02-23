#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }  
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];     // 왼쪽 테두리
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];   // 오른쪽 테두리

        for (int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[n-1][i]);
    }

    cout << answer << '\n';

    return 0;
}

// 7
// 3 8 
// 8 1 0
// 2 7 4 4

// 자기랑 같은 곳 or 자기 보다 1 큰 곳에서 옴 
// 마지막 줄에 대해서 최대값 구하면 됨 
