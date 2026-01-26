#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;   

    int dp[1005][3];
    int r[1005], g[1005], b[1005];

    for (int i = 1; i <= N; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    // DP[i][0] : i번째 집까지 칠할 때 비용 최소값 (i 집은 빨간색)
    // DP[i][1] : i번째 집까지 칠할 때 비용 최소값 (i 집은 초록색)
    // DP[i][2] : i번째 집까지 칠할 때 비용 최소값 (i 집은 파랑색)
    dp[1][0] = r[1];
    dp[1][1] = g[1];
    dp[1][2] = b[1];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g[i];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i];
    }

    cout << *min_element(dp[N], dp[N] + 3) << "\n";

    return 0;
}
