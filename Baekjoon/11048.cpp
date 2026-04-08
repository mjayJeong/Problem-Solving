#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> maze(N, vector<int>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maze[i][j];
    }
  }
  
  vector<vector<int>> dp(N, vector<int>(M, 0));   // dp 배열 : 최대 사탕 개수 
  dp[0][0] = maze[0][0];

  for (int i = 1; i < N; i++) {
    dp[i][0] = dp[i-1][0] + maze[i][0];
  }
  for (int i = 1; i < M; i++) {
    dp[0][i] = dp[0][i-1] + maze[0][i];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < M; j++) {
      dp[i][j] = max({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + maze[i][j];
    }
  }

  cout << dp[N-1][M-1] << '\n';

  return 0;
}
