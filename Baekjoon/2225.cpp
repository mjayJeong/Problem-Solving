#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  // i개를 더해서 합이 j가 되는 경우의 수
  vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

  // 합이 0이면 전부 1가지
  for (int i = 1; i <= K; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j]= (dp[i][j-1] + dp[i-1][j]) % MOD;
    }
  }

  cout << dp[K][N] << '\n';

  return 0;
}
