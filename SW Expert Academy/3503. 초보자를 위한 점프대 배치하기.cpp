#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
      cin >> height[i];
    }

    sort(height.begin(), height.end());

    int answer = 0;

    for (int i = 2; i < N; i++) {
      answer = max(answer, abs(height[i] - height[i-2]));
    }

    cout << '#' << t << ' ' << answer << '\n';
  }

  return 0; 
}
