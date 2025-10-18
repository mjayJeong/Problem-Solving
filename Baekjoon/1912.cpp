#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() 
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int dp[100001];
    dp[0] = v[0]; 

    int answer = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(v[i], (dp[i-1] + v[i]));
        if (answer < dp[i]) answer = dp[i];
    }
    
    cout << answer;

    return 0;
}
