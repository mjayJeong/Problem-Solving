#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> t(N), p(N);
    for (int i = 0; i < N; i++) cin >> t[i] >> p[i];

    vector<long long> dp(N + 1, 0);
    long long max_val = 0;

    for (int i = 0; i < N; i++) {
        dp[i] = max(dp[i], max_val);          // i일까지의 최댓값 반영
        int nxt = i + t[i];
        if (nxt <= N) {
            dp[nxt] = max(dp[nxt], dp[i] + p[i]);
        }
        max_val = max(max_val, dp[i]);
    }

    // 마지막 날도 갱신된 값 반영
    max_val = max(max_val, dp[N]);

    cout << max_val << "\n";
    return 0;
}
