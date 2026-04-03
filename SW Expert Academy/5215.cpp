#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tt = 1; 

  while (T--) {

    int N, L;
    cin >> N >> L;
    vector<pair<int, int>> ham(N);
    int dp[21][10001] = {0};

    for (int i = 0; i < N; i++) {
      int t, k;
      cin >> t >> k;
      ham[i].first = t;
      ham[i].second = k;
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= L; j++) {
        int wi = ham[i-1].second;
        int vi = ham[i-1].first;

        if (wi > j) {
          dp[i][j] = dp[i-1][j];
        } else {
          dp[i][j] = max(dp[i-1][j], vi + dp[i-1][j-wi]);
        }
      }
    }
    cout << "#" << tt << ' ' << dp[N][L] << '\n';
    tt++;
  }

  return 0;
}
