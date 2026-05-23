#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N, K;
    cin >> N >> K;
    vector<int> level(N);
    for (int i = 0; i < N; i++) {
      cin >> level[i];
    }

    sort(level.begin(), level.end());

    double answer = 0; 
    
    for (int i = N - K; i < N; i++) {
      answer = (answer + level[i]) / 2.0;
    }
    
    cout << '#' << t << ' ' << fixed << setprecision(6) << answer << '\n';

  }

  return 0;
}
