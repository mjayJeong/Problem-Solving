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
    int N, M;
    cin >> N >> M;
    vector<int> price(N);

    for (int i = 0; i < N; i++) {
      cin >> price[i];
    }

    int left = 0, right = 0;
    long long sum = 0; 
    int answer = 0; 
    
    while (true) {
      if (sum >= M) {
        if (sum == M) answer++;
        sum -= price[left];
        left++;
      } else {
        if (right == N) break;
        sum += price[right];
        right++;
      }
    }
    cout << "#" << t << " " << answer << '\n';
  }

  return 0;
}
