#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int tc = 1;

  while (T--) {
    int N;
    cin >> N;
    vector<int> price(N);

    for (int i = 0; i < N; i++) {
      cin >> price[i];
    }
    
    long long answer = 0;
    int maxPrice = price[N-1];

    for (int i = N-1; i >= 0; i--) {
      if (price[i] < maxPrice) {
        answer += maxPrice - price[i];
      } else {
        maxPrice = price[i];
      }
    }

    cout << '#' << tc << ' ' << answer << '\n';
    tc++;
  }

  return 0;
}
