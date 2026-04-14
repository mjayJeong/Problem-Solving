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
    vector<pair<int, int>> bus(N);

    for (int i = 0; i < N; i++) {
      cin >> bus[i].first >> bus[i].second;
    }

    int P;
    cin >> P;
    vector<int> stop(P);
    for (int i = 0; i < P; i++) {
      cin >> stop[i];
    }

    vector<int> answer(5001, 0);
    for (int i = 0; i < N; i++) {
      int start = bus[i].first;
      int end = bus[i].second;
      for (int j = start; j <= end; j++) {
        answer[j]++;
      }
    }

    cout << '#' << tc << ' ';
    for (int i = 0; i < P; i++) {
      cout << answer[stop[i]] << ' ';
    }
    cout << '\n';
    tc++;
  }

  return 0;
}
