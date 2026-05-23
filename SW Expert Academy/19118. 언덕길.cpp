#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> home(N);
    for (int i = 0; i < N ; i++) {
      cin >> home[i];
    }

    vector<int> dp(N, 1);
    int max_len = 0; 

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (home[j] < home[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_len = max(max_len, dp[i]);
    }

    cout << '#' << t << ' ' << N - max_len << '\n';

  }

  return 0;
}
