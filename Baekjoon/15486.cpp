#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int time[1500001], price[1500001];
    int dp[1500002] = {0}; 

    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> price[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (i + time[i] <= n + 1) {
            dp[i + time[i]] = max(dp[i + time[i]], dp[i] + price[i]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n + 1];
    return 0;
}
