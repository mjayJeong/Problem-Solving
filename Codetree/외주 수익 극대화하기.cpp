#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];

    // n+2까지 만들어 두면 i+t[i]가 n+1인 경우도 안전
    vector<long long> dp(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        // 오늘까지의 최댓값을 다음 날로 전파
        dp[i] = max(dp[i], dp[i - 1]);

        // i일부터 시작하는 일을 끝낼 수 있으면 갱신
        int endDay = i + t[i];
        if (endDay <= n + 1) {
            dp[endDay] = max(dp[endDay], dp[i] + p[i]);
        }
    }
    // 마지막 날 이후까지 전파
    dp[n + 1] = max(dp[n + 1], dp[n]);

    cout << dp[n + 1] << '\n';
    return 0;
}
