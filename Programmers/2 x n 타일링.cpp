#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int MOD = 1000000007; 
    
    int dp[60001];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    
    return dp[n];
}
