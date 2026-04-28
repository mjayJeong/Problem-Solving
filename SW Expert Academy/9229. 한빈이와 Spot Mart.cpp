#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer = -1;
    int left = 0, right = N - 1;
    while (left < right) {
      if (arr[left] + arr[right] <= M) {
        answer = max(answer, arr[left] + arr[right]);
        left++;
      } else {
        right--;
      }
    }

    if (answer == -1) cout << '#' << t << ' ' << -1 << '\n';
    else cout << '#' << t << ' ' << answer << '\n';
  }

  return 0;
}
