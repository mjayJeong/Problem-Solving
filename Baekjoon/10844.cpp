#include <iostream>
#define MOD 1000000000

using namespace std;


int main()
{
    int n;
    scanf("%d", &n);
    int dp[101][11];

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][j] = dp[i-1][1] % MOD;
            else if (j == 9) dp[i][j] = dp[i-1][8] % MOD;
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer += dp[n][i];
    }

    cout << answer % MOD;
    return 0;
}
