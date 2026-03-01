#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<long long> mix(N);
  for (int i = 0; i < N; i++) {
    cin >> mix[i];
  }

  int left = 0, right = N-1;
  long long best = LLONG_MAX;
  long long ans1 = mix[left], ans2 = mix[right];

  while (left < right) {
    long long s = mix[left] + mix[right];
    long long ab = llabs(s);

    if (ab < best) {
      best = ab;
      ans1 = mix[left];
      ans2 = mix[right];
    }

    if (s < 0) left++;
    else if (s > 0) right--;
    else break;
  }

  cout << ans1 << ' ' << ans2 << '\n';

  return 0;
}
