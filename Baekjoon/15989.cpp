#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    vector<vector<int>> dp(10001, vector<int>(4));
    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        for (int j = 4; j <= n; j++) {
            dp[j][1] = 1;
            dp[j][2] = dp[j-2][1] + dp[j-2][2];
            dp[j][3] = dp[j-3][1] + dp[j-3][2] + dp[j-3][3];
        }

        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }

    return 0;
}
